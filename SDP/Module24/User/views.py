from django.shortcuts import render, redirect, get_object_or_404
from django.views.generic import TemplateView, View, ListView
from django.views.generic.edit import CreateView, FormView
from django.contrib.auth import logout, login
from django.contrib.auth.views import LoginView, LogoutView
from .forms import RegistrationsForm, ProfileForm, DepositBalanceForm
from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from .models import Profile
from Books.models import BorrowedBooks, Books
from Books.forms import AddReviewsForm
from django.contrib import messages



class RegistrationsView(CreateView):
	form_class = RegistrationsForm
	template_name = 'register.html'
	success_url = reverse_lazy('add_book')

	def form_valid(self, form):
		user = form.save()  
		if user:
			Profile.objects.get_or_create(user=user)
			login(self.request, user)
		return super().form_valid(form)

class LoginView(LoginView):
	template_name = 'login.html'
	def get_success_url(self):
		return reverse_lazy('add_book')

class LogOutView(LogoutView):
	def get_success_url(self):
		if self.request.user.is_authenticated:
			logout(self.request)
		return reverse_lazy('register')


def ProfileView(request):
	profile = request.user.profile

	# user profile details displaying 
	if request.method=="POST" and 'deposit_balance' in request.POST:
		deposit_form = DepositBalanceForm(request.POST)
		
		if deposit_form.is_valid():
				amount = deposit_form.cleaned_data['balance']
				profile.balance+=amount
				profile.save()
				return redirect('add_book')
	else:
		deposit_form= DepositBalanceForm()
	
	# borrowed books showing on table
	borrowed_books = BorrowedBooks.objects.filter(user=request.user)

	if request.method == 'POST' and 'return_book' in request.POST:
		book_id = request.POST.get('book_id')
		# Returning book method 
		borrowed_book = BorrowedBooks.objects.get(id=book_id, user=request.user)
		if borrowed_book:
			profile.balance +=borrowed_book.book.price
			profile.save()
			borrowed_book.delete()
			messages.success(request, f'You have successfully returned {borrowed_book.book.title}!')
		return redirect('profile')

	# Handle review submission
	if request.method == 'POST' and 'add_review' in request.POST:
		review_form = AddReviewsForm(request.POST)
		book_id = request.POST.get('book_id')
		book = get_object_or_404(Books, id=book_id)

		if review_form.is_valid():
			review = review_form.save(commit=False)
			review.user = request.user
			review.book = book
			review.save()
			messages.success(request, f'Thank you for reviewing {book.title}!')
			return redirect('profile')
	else:
		review_form = AddReviewsForm()
		
	return render(request, 'profile.html', {
        'deposit_form': deposit_form, 
        'review_form': review_form, 
        'profile': profile, 
        'borrowed_books': borrowed_books
    })
	
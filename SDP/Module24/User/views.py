from django.shortcuts import render, redirect
from django.views.generic import TemplateView, View, ListView
from django.views.generic.edit import CreateView, FormView
from django.contrib.auth import logout, login
from django.contrib.auth.views import LoginView, LogoutView
from .forms import RegistrationsForm, ProfileForm, DepositBalanceForm
from django.contrib.auth.decorators import login_required
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from .models import Profile
from Books.models import BorrowedBooks
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

# @login_required
# class ProfileView(CreateView):
# 	model= Profile
# 	template_name = 'profile.html'
# 	success_url = reverse_lazy('add_book')

# 	def form_valid(self, form):
# 			form.save()
# 			return super().form_valid(form)


def ProfileView(request):
	profile = request.user.profile
	if request.method=="POST":
		form = DepositBalanceForm(request.POST)
		
		if form.is_valid():
				amount = form.cleaned_data['balance']
				profile.balance+=amount
				profile.save()
				return redirect('add_book')
	else:
		form = DepositBalanceForm()
	

	borrowed_books = BorrowedBooks.objects.filter(user=request.user)
	if request.method == 'POST':
		book_id = request.POST.get('book_id')
		print('bookId', book_id)
		borrowed_book = BorrowedBooks.objects.get(id=book_id, user=request.user)

		if borrowed_book:
			profile.balance +=borrowed_book.book.price
			profile.save()
			borrowed_book.delete()
			messages.success(request, f'You have successfully returned {borrowed_book.book.title}!')
		return redirect('profile')
	return render(request, 'profile.html', {'form':form, 'profile':profile, 'borrowed_books':borrowed_books})
	
	
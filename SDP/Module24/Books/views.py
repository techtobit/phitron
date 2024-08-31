from django.shortcuts import render, redirect
from django.urls import reverse_lazy
from django.db.models import Avg
from django.views.generic.edit import FormView
from django.views.generic import DetailView
from .forms import AddBooksForm, AddCategoryForm, AddReviewsForm
from .models import Books, BorrowedBooks
from django.contrib import messages

# Create your views here.

class AddBooksView(FormView):
	form_class = AddBooksForm
	template_name = 'addBooks.html'
	success_url = reverse_lazy('add_category')

	def form_valid(self, form):
			form.save()
			print(form)
			return super().form_valid(form)

class AddCategoryView(FormView):
	form_class = AddCategoryForm
	template_name = 'addBooksCategory.html'
	success_url = reverse_lazy('add_book')

	def form_valid(self, form):
			form.save()
			return super().form_valid(form)


class BookDetialsView(DetailView):
	model = Books
	template_name = 'bookDetails.html'
	context_object_name = 'book'
	pk_url_kwarg= 'id'
	
	def get_context_data(self, **kwargs):
		context = super().get_context_data(**kwargs)
		book = self.get_object()
		# average_rating = book.reviews.aggregate(Avg('rate'))['rate__avg']
		# average_rating = book.reviews.aggregate(average=Avg('rate'))['average']
		average_rateing = book.reviews.aggregate(Avg('rate'))['rate__avg']
		context['average_rating'] = average_rateing if average_rateing is not None else 'No ratings yet'
		# print("average_rateing", context['average_rating'])
		return context

	def post(self, request, *args, **kwargs):
		book = self.get_object()
		print(book)
		profile = request.user.profile

		if profile.balance >= book.price:
			print(profile.balance ,book.price)
			profile.balance -=book.price
			profile.save()

			BorrowedBooks.objects.create(user=request.user, book=book)
			messages.success(request, f'You Have Successfully Borrowed {book.title}')
			return redirect('profile')
		else:
			messages.success(request, f'You donot have enough balance')
			return redirect('book-details', id=book.id)

			
class AddReviewView(FormView):
	form_class = AddReviewsForm
	template_name = 'displayBooks.html'
	success_url = reverse_lazy('add_book')

	def form_valid(self, form):
			form.save()
			return super().form_valid(form)


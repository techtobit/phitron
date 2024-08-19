from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic.edit import FormView
from django.views.generic import DetailView
from .forms import AddBooksForm, AddCategoryForm, AddReviewsForm
from .models import Books

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

			
class AddReviewView(FormView):
	form_class = AddReviewsForm
	template_name = 'displayBooks.html'
	success_url = reverse_lazy('add_book')

	def form_valid(self, form):
			form.save()
			return super().form_valid(form)


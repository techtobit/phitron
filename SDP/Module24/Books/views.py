from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic.edit import FormView
from .forms import AddBooksForm, AddCategoryForm

# Create your views here.

class AddBooksView(FormView):
	form_class = AddBooksForm
	template_name = 'addBooks.html'
	success_url = reverse_lazy('')

	def form_valid(self, form):
			# form
			print(form)
			return super().form_valid(form)

class AddCategoryView(FormView):
	form_class = AddCategoryForm
	template_name = 'addBooksCategory.html'
	success_url = reverse_lazy('add_book')

	def form_valid(self, form):
			form.save()
			return super().form_valid(form)
	


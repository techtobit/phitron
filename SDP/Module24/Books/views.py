from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic.edit import FormView
from .forms import AddBooksForm

# Create your views here.

class AddBooksView(FormView):
	form_class = AddBooksForm
	template_name = 'addBooks.html'
	success_url = reverse_lazy('')

	def form_valid(self, form):
			# form
			return super().form_valid(form)
	


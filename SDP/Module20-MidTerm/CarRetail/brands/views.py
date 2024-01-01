from django.shortcuts import render
from . import forms
from . import models
from django.urls import reverse_lazy
from django.views.generic import CreateView


class AddBrand(CreateView):
    model = models.Brand
    form_class = forms.BrandFrom
    template_name = 'add_brand.html'
    success_url = reverse_lazy('add_brand')
    def form_valid(self, form):
        return super().form_valid(form)
    

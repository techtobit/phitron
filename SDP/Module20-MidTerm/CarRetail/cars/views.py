from django.shortcuts import render
from . import forms
from . import models
from django.urls import reverse_lazy
from django.views.generic import CreateView

class AddCar(CreateView):
    model = models.Cars
    form_class = forms.CarsFrom
    template_name = 'add_cars.html'
    success_url = reverse_lazy('add_cars')
    def form_valid(self, form):
        return super().form_valid(form)
    

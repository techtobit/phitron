from django.shortcuts import render
from . import forms
from cars.models import Cars
from django.urls import reverse_lazy
from django.views.generic import CreateView,DetailView

class AddCar(CreateView):
    model = Cars
    form_class = forms.CarsFrom
    template_name = 'add_cars.html'
    success_url = reverse_lazy('add_cars')
    def form_valid(self, form):
        return super().form_valid(form)

class DetailPostView(DetailView):
    model = Cars
    context_object_name = 'car'
    pk_url_kwarg = 'id'
    template_name = 'detail_post.html'

    
from django.forms.models import BaseModelForm
from django.http import HttpResponse
from django.shortcuts import render
from . import forms
from . import models
from django.views.generic import CreateView, UpdateView, DeleteView
from django.urls import reverse_lazy
from django.utils.decorators import method_decorator
from django.contrib.auth.decorators import login_required

# Create your views here.


@method_decorator(login_required, name='dispatch')
class AddMusicianView(CreateView):
    model = models.Musician
    form_class = forms.MusicianForm
    template_name = 'add_musician.html'
    success_url = reverse_lazy('add_musician')
    def form_valid(self, form):
        return super().form_valid(form)
    
from django.shortcuts import render
from django.views.generic import CreateView, UpdateView, DeleteView
from . models import Album
from . import forms
from django.urls import reverse_lazy
# Create your views here.


class AddAlbumView(CreateView):
    model = Album
    form_class = forms.AlbumForm
    template_name = 'add_album.html'
    success_url = reverse_lazy('add_album')
    def form_valid(self, form):
        return super().form_valid(form)
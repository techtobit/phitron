from django.shortcuts import render
from django.views.generic import CreateView, UpdateView, DeleteView
from . models import Album
from . models import Musician
from . import forms
from django.urls import reverse_lazy
from django.contrib.auth.decorators import login_required
from django.utils.decorators import method_decorator


@method_decorator(login_required, name='dispatch')
class AddAlbumView(CreateView):
    model = Album
    form_class = forms.AlbumForm
    template_name = 'add_album.html'
    success_url = reverse_lazy('add_album')
    def form_valid(self, form):
        return super().form_valid(form)
    
class EditAlbumView(UpdateView):
    model = Album
    form_class = forms.AlbumForm
    template_name = 'add_album.html'
    pk_url_kwarg = 'id'
    success_url = reverse_lazy('home')


class DeleteAlbumView(DeleteView):
    model = Album
    template_name = 'delete_album.html'
    success_url = reverse_lazy('home')
    pk_url_kwarg = 'id'
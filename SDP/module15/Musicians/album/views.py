from django.shortcuts import render, redirect
from . import forms
# Create your views here.

def add_album(request):
    if request.method == "POST":
        form = forms.AlbumForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('add_album')
    else:
        form = forms.AlbumForm()
    return render(request, 'musician.html', {'form':form})

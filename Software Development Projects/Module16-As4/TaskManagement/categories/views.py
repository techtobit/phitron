from django.shortcuts import render, redirect
from . import forms

# Create your views here.

def add_categorie(request):
    if request.method=='POST':
        categorie_form = forms.CategorieForm(request.POST)
        if categorie_form.is_valid():
            categorie_form.save()
            return redirect('add_categorie')
    else:
        categorie_form = forms.CategorieForm()
    return render(request, 'add_categorie.html', {'form':categorie_form})
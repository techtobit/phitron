from django.shortcuts import render, redirect
from django.utils.decorators import method_decorator
from django.contrib.auth.decorators import login_required
from . import forms
# Create your views here.
# @method_decorator(login_required, name='dispatch')

@login_required
def add_categories(request):
    if request.method == "POST":
        category_form = forms.CategoriesFrom(request.POST)
        if category_form.is_valid():
            category_form.save()
            return redirect('add_category')
        
    else:
        category_form = forms.CategoriesFrom()
    return render(request, 'add_category.html', {'form': category_form})


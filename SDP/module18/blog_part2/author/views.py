from django.shortcuts import render, redirect
from django.contrib import messages
from django.contrib.auth import authenticate, login
from django.contrib.auth.forms import AuthenticationForm, UserChangeForm
from django.contrib.auth.models import User
from . import forms
# Create your views here.

def register(request):
    if request.method == 'POST':
        register_form = forms.RegistrationsForm(request.POST)
        if register_form.is_valid():
            register_form.save()
            messages.success(request, 'Account Created Successfully')
            return redirect('register')
    else:
        register_form = forms.RegistrationsForm()
    return render(request, 'register.html', {'form': register_form, 'type':'Register'})


# class ChangeUserForm(UserChangeForm):
#     password=None
#     class Meta:
#         model = User
#         fields = ['username', 'first']



def user_login(request):
    if request.method == 'POST':
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            user_name = form.cleaned_data['username']
            user_pass = form.cleaned_data['password']
            user = authenticate(username=user_name, password = user_pass)
        if user is not None:
            messages.success(request, 'Logged in Successfully')
            login(request, user)
            return redirect('home')
        else:
            messages.warning(request, 'Login Information Incorrect')
            return redirect('register')
    else:
        form = AuthenticationForm()
    return render(request, 'register.html', {'form': form, 'type': 'login'})





def add_author(request):
    if request.method == 'POST':
        author_form = forms.AuthorForm(request.POST)
        if author_form.is_valid():
            author_form.save()
            return redirect('add_author')
    
    else:
        author_form = forms.AuthorForm()
    return render(request, 'add_author.html', {'form' : author_form})
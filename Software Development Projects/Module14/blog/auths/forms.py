from django.contrib.auth.models import User
from django.shortcuts import redirect, render
from django.contrib.auth import authenticate
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django import forms

class RegisterForm(UserCreationForm):
    first_name=forms.CharField(widget=forms.TextInput(attrs={'id' : 'required'}))
    last_name=forms.CharField(widget=forms.TextInput(attrs={'id' : 'required'}))
    email=forms.CharField(widget=forms.EmailInput(attrs={'id' : 'required'}))

    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email']



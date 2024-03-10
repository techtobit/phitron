from typing import Any
from django.contrib.auth.forms import AuthenticationForm
from django.db.models.base import Model as Model
from django.db.models.query import QuerySet
from django.shortcuts import render,redirect
from django.views import View
from . import forms
from django.contrib.auth.models import User
from django.views.generic import UpdateView
from django.contrib.auth.views import LoginView
from django.contrib import messages
from django.urls import reverse_lazy
from django.contrib import messages
from django.contrib.auth import logout


class RegisterView(View):
    template_name = 'register.html'

    def get(self, request,*args, **kwargs):
        register_form = forms.RegistrationsForm()
        return render(request, self.template_name, {"form":register_form})

    def post(self, request, *args, **kwargs):
        register_form = forms.RegistrationsForm(request.POST)
        if register_form.is_valid():
            register_form.save()
            messages.success(request, 'Account Created Successfully')
            return redirect('login')
        else:
            print(register_form.errors)
        return render(request, self.template_name, {'form': register_form})
    

class UserLogInView(LoginView):
    template_name = 'login.html'
    def get_success_url(self):
        return reverse_lazy('home')
    def form_valid(self, form):
        messages.success(self.request, 'Logged in successfull')
        return super().form_valid(form)
    def form_invalid(self, form):
        messages.success(self.request, 'Logged information incorrect')
        return super().form_invalid(form)
    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context["type"] = 'login'
        return context
    

class UserLogOutView(View):
    def get(self, request):
        logout(request)
        return redirect('login')

class UpdateProfileView(UpdateView):
    model = User
    fields = fields = ['username', 'first_name', 'last_name', 'email']
    template_name = 'update_profile.html'
    success_url = reverse_lazy('update_profile')

    def form_valid(self, form):
        messages.success(self.request, 'Profile Updated')
        return super().form_valid(form)
    
    def get_object(self):
        return self.request.user
    


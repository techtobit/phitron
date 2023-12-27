from django.shortcuts import render, redirect
from django.views import View
from django.contrib import messages
from . import forms
# Create your views here.

class RegisterView(View):
    template_name = 'signup.html'

    def get(self, request, *args, **kwargs):
        register_form = forms.RegistrationsForm()
        return render(request, self.template_name, {'form': register_form, 'type': 'Register'})
    
    def post(self, request, *args, **kwargs):
        register_form = forms.RegistrationsForm(request.POST)
        if register_form.is_valid():
            register_form.save
            messages.success(request,'Account Created Successfully')
            return redirect('home')
        return render(request, self.template_name, {'form': register_form,  'type': 'Register'})
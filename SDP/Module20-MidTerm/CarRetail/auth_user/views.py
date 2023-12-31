from django.shortcuts import render,redirect
from django.views import View
from . import forms
from django.contrib.auth.views import LoginView
from django.contrib import messages


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
            return redirect('register')
        else:
            print(register_form.errors)
        return render(request, self.template_name, {'form': register_form})
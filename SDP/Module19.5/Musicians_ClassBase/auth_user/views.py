from django.shortcuts import render, redirect
from django.views import View
from django.contrib import messages
from . import forms
from django.contrib.auth.views import LoginView, LogoutView
from django.contrib.auth import logout
from django.urls import reverse_lazy
# Create your views here.



# def register(request):
#     if request.method == 'POST':
#         register_form = forms.RegistrationsForm(request.POST)
#         if register_form.is_valid():
#             register_form.save()
#             messages.success(request, 'Account Created Successfully')
#             return redirect('register')
#     else:
#         register_form = forms.RegistrationsForm()
#     return render(request, 'signup.html', {'form': register_form, 'type':'Register'})

class UserLoginView(LoginView):
    template_name = 'login.html'
    def get_success_url(self):
        return reverse_lazy('home')
    def form_vaild(self, form ):
        messages.success(self.request, 'Logged in successful')
        return super().form_valid(form)
    def form_invalid(self, form):
        messages.success(self.request, 'Logged information incorrect')
        return super().form_invalid(form)
    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        context['type'] = 'Login'
        return context

class SessionLogoutView(View):
    def get(self, request, *args, **kwargs):
        logout(request)
        return redirect('user_login')

class RegisterView(View):
    template_name = 'signup.html'

    def get(self, request, *args, **kwargs):
        register_form = forms.RegistrationsForm()
        return render(request, self.template_name, {'form': register_form, 'type': 'Register'})
    
    def post(self, request, *args, **kwargs):
        register_form = forms.RegistrationsForm(request.POST)
        if register_form.is_valid():
            register_form.save()
            messages.success(request, 'Account Created Successfully')
            return redirect('register')
        else:
            print(register_form.errors)
        return render(request, self.template_name, {'form': register_form,  'type': 'Register'})
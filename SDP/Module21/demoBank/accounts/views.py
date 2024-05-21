from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic import FormView
from django.contrib.auth import login, logout
from django.contrib.auth.views import LoginView, LogoutView
from .form import RegistrationsForm

class UserRegistrationView(FormView):
    template_name = 'registration.html'
    form_class = RegistrationsForm
    success_url = reverse_lazy('login')
    
    def form_valid(self,form):
        user = form.save()
        login(self.request, user)
        return super().form_valid(form)


class UserLoginView(LoginView):
	template_name= 'login.html'
	def get_success_url(self):
		return reverse_lazy('home')

class UserLogOutView(LogoutView):
	def get_success_url(self):
		if self.request.user.is_authenticated:
			logout(self.request)
		return reverse_lazy('home')
				
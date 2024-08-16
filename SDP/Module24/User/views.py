from django.shortcuts import render
from django.views.generic import TemplateView
from django.views.generic.edit import CreateView
from django.contrib.auth import logout
from django.contrib.auth.views import LoginView, LogoutView
from .forms import RegistrationsForm
from django.urls import reverse_lazy


class RegistrationsView(CreateView):
	form_class = RegistrationsForm
	template_name = 'register.html'
	success_url = reverse_lazy('')

	def form_valid(self, form):
			user = form.save()
			if user:
				login(self.request, user)
			return super().form_valid(form)

class LoginView(LoginView):
	template_name = 'login.html'
	def get_success_url(self):
		return reverse_lazy('register')

class LogOutView(LogoutView):
	def get_success_url(self):
		if self.request.user.is_authenticated:
			logout(self.request)
		return reverse_lazy('login')
	
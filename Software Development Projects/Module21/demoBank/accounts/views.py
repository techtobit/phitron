from django.shortcuts import render, redirect
from django.urls import reverse_lazy
from django.views.generic import FormView
from django.views import View
from django.contrib.auth import login, logout
from django.contrib.auth.views import LoginView, LogoutView
from .form import RegistrationsForm, UserUpdateForm

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

class UserUpdateView(View):
	template_name = 'profile.html'

	def get(self, request):
		form = UserUpdateForm(instance=request.user)
		return render(request, self.template_name, {'form':form})
	
	def post(self, request):
		form = UserUpdateForm(request.POST, instance = request.user)
		if form.is_valid():
			form.save()
			return redirect('profile')
		return render(request, self.template_name, {'form':form})
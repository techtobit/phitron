from django.shortcuts import render
from django.contrib.auth import logout
from django.views.generic import TemplateView
from django.contrib.auth.views import LoginView, LogoutView
# Create your views here.

class HomeView(TemplateView):
	template_name = 'index.html'




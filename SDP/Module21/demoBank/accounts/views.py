from django.shortcuts import render
from django.urls import reverse_lazy
from django.views.generic import FormView
from .form import RegistrationsForm

class UserRegistrationView(FormView):
    template_name = 'registration.html'
    form_class = RegistrationsForm
    success_url = reverse_lazy('')
    
    def form_valid(self,form):
        user = form.save()
        # login(self.request, user)
        return super().form_valid(form)
				
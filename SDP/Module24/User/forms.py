from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User
from django import forms
from .models import Profile

class RegistrationsForm(UserCreationForm):
	class Meta:
		model = User
		fields = ['username', 'first_name', 'last_name', 'email']

class ProfileForm(forms.ModelForm):
		class Meta:
				model = Profile
				fields = ("__all__")

class DepositBalanceForm(forms.ModelForm):
	class Meta:
		model = Profile
		fields=['balance']
		labels = {
            'balance': 'Deposit Amount', 
        }

	

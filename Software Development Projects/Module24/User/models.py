from django.db import models
from django.forms import ModelForm
from django.contrib.auth.models import User


# Create your models here.


class Profile(models.Model):
	user = models.OneToOneField(User, related_name='profile', on_delete=models.CASCADE)
	balance = models.DecimalField(max_digits=10, decimal_places=2, default=0.0)
	
	def __str__(self):
		return f"{self.user.username}'s Profile"
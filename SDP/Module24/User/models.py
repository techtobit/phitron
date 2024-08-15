from django.db import models
from django.forms import ModelForm

# Create your models here.

class Account(models.Model):
	name = models.CharField(max_length=100)
	email = models.EmailField(max_length=254)
	password = models.CharField(max_length=30)
	password2 = models.CharField(max_length=30)

	def __str__(self):
			return f"Name -{self.name}, Email- {self.email}"
	

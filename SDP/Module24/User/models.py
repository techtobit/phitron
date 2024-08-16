from django.db import models
from django.forms import ModelForm
from django.contrib.auth.models import User


# Create your models here.


class Profile(models.Model):
	user = models.OneToOneField(User, related_name='account', on_delete=models.CASCADE)
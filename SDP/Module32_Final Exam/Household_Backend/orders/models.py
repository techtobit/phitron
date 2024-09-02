from django.db import models
from django.contrib.auth.models import User
from services.models import Service
# from django.conf import settings
# User = settings.AUTH_USER_MODEL

class Cart(models.Model):
	customer=models.ForeignKey(User, on_delete=models.CASCADE)
	service=models.ForeignKey(Service, on_delete=models.CASCADE)

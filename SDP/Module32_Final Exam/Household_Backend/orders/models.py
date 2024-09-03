from django.db import models
from django.contrib.auth.models import User
from services.models import Service


class Cart(models.Model):
	customer=models.ForeignKey(User, on_delete=models.CASCADE)
	service=models.ForeignKey(Service, on_delete=models.CASCADE)


class Ordered(models.Model):
	cart=models.ForeignKey(Cart, on_delete=models.CASCADE)
	address=models.CharField( max_length=50)
	# created_on=models.DateTimeField(auto_now_add=True)

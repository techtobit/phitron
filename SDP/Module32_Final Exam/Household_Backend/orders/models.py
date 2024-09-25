from django.db import models
from django.contrib.auth.models import User
from services.models import Service, Categorie
# from django.contrib.postgres.fields import ArrayField


class Cart(models.Model):
	customer=models.ForeignKey(User, on_delete=models.CASCADE)
	service=models.ForeignKey(Service, on_delete=models.CASCADE)
	category=models.CharField( max_length=50)
	# categories = models.CharField(max_length=255, blank=True)
	price=models.DecimalField( max_digits=5, decimal_places=2)
	# created_at= models.DateField( auto_now=False, auto_now_add=False)

	def __str__(self):
			return self.customer.username


class Ordered(models.Model):
	cart=models.ForeignKey(Cart, on_delete=models.CASCADE)

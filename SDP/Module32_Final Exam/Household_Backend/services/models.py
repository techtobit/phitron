from django.db import models

# Create your models here.

class Service(models.Model):
	name=models.CharField(max_length=50)
	category=models.CharField(max_length=50)
	discription=models.TextField(max_length=200)
	price=models.DecimalField( max_digits=5, decimal_places=2)
	created_on=models.DateTimeField(auto_now_add=True)

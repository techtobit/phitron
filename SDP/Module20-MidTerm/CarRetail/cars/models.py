from django.db import models
from brands.models import Brand

class Cars(models.Model):
    car_name = models.CharField(max_length=20)
    car_brand = models.ForeignKey(Brand, on_delete=models.CASCADE)
    car_image = models.ImageField(upload_to='static/images')
    description = models.CharField(max_length=20)
    quantity = models.IntegerField()
    price = models.IntegerField()

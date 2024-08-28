from django.db import models

# Create your models here.

class Service(models.Model):
	name=models.CharField( max_length=50)
	discription=models.TextField(max_length=150)
	imgae=models.ImageField( upload_to='service/media')

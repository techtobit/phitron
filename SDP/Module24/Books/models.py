from django.db import models

class Books(models.Model):
	title = models.CharField(max_length=200)
	author = models.CharField(max_length=100)
	description = models.CharField(max_length=400)
	image = models.ImageField( upload_to=None, height_field=None, width_field=None, max_length=None)
	price = models.IntegerField(max_length=20)


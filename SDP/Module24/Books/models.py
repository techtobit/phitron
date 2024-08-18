from django.db import models


class BookCategory(models.Model):
	category = models.CharField(max_length=200)

class Books(models.Model):
	title = models.CharField(max_length=200)
	author = models.CharField(max_length=100)
	description = models.CharField(max_length=400)
	image = models.ImageField( upload_to=None, height_field=None, width_field=None, max_length=None)
	price = models.IntegerField()
	categories = models.ManyToManyField(BookCategory, related_name='categories' )




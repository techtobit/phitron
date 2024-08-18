from django.db import models

class Categories(models.Model):
	category = models.CharField(max_length=200)

	def __str__(self):
		return self.category

class Books(models.Model):
	title = models.CharField(max_length=200)
	author = models.CharField(max_length=100)
	category = models.ManyToManyField(Categories)
	price = models.IntegerField()
	image = models.ImageField( upload_to=None, height_field=None, width_field=None, max_length=None)
	description = models.TextField()
    
	def __str__(self):
		return f"{self.title} - {self.author} - {self.category}"
	




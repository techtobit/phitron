from django.db import models
from .constrant import REVIEW
from django.contrib.auth.models import User
from datetime import datetime

class Categories(models.Model):
	category = models.CharField(max_length=200)
	slug = models.SlugField(unique=True, max_length=100)


	def __str__(self):
		return self.category

class Books(models.Model):
	title = models.CharField(max_length=200)
	author = models.CharField(max_length=100)
	category = models.ManyToManyField(Categories)
	price = models.IntegerField()
	image = models.ImageField(upload_to='Books/media/')
	description = models.TextField()
    
	def __str__(self):
		return f"{self.title} || {self.author} || {self.price}"

class BorrowedBooks(models.Model):
	user = models.ForeignKey(User, on_delete=models.CASCADE)
	book = models.ForeignKey(Books, on_delete=models.CASCADE)
	borrowed_on = models.DateTimeField(default=datetime.now)



class Reviews(models.Model):
	user = models.ForeignKey(User, on_delete=models.CASCADE)
	book = models.ForeignKey(Books, related_name='review', on_delete=models.CASCADE)
	rate = models.CharField(max_length=10, choices=REVIEW)
	body= models.TextField()
	created_at = models.DateTimeField(auto_now_add=True)

	def __str__(self):
		return f"Review by {self.user.username} for {self.book.title}"

	




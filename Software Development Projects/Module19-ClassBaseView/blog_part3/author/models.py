from django.db import models
from django import forms 


# Create your models here.

class Author(models.Model):
    name=models.CharField(max_length=100)
    bio=models.TextField()
    phone_no=models.CharField(max_length=12)

    def __str__(self) -> str:
        return self.name




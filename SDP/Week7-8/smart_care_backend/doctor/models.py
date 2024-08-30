from django.db import models
from django.contrib.auth.models import User


class Specialization(models.Model):
	name=models.CharField(max_length=50)
	slug=models.SlugField(max_length=50)
	def __str__(self):
			return self.name
	

class Designation(models.Model):
	name=models.CharField(max_length=50)
	slug=models.SlugField(max_length=50)
	def __str__(self):
		return self.name


class AvailableTime(models.Model):
    name = models.CharField(max_length = 100)
    
    def __str__(self):
        return self.name

class Doctor(models.Model):
	user=models.OneToOneField(User, related_name='doctor', on_delete=models.CASCADE)
	image=models.ImageField( upload_to='doctor/media', )
	Specialization=models.ManyToManyField(Specialization)
	Designation=models.ManyToManyField(Designation)
	AvailableTime=models.ManyToManyField(AvailableTime)
	bio= models.TextField(max_length=50)
	fee=models.CharField( max_length=12)

	def __str__(self):
		return f"{self.user.first_name} - {self.user.last_name}"


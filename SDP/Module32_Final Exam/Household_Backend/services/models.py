from django.db import models
from accounts.models import SellerProfile

JOB_CATEGORY=(
	('electrician', 'Electrician'),
	('plumber', 'Plumber'),
	('internet', 'Internet Fixer'),
	('cleaner', 'House Cleaner'),
)

RATEING=(
	('1', '⭐'),
	('2', '⭐⭐'),
	('3', '⭐⭐⭐'),
	('4', '⭐⭐⭐⭐'),
	('5', '⭐⭐⭐⭐⭐'),
)

class Service(models.Model):
	seller=models.ForeignKey(SellerProfile,  on_delete=models.CASCADE)
	service_title=models.CharField(max_length=50)
	category=models.CharField(max_length=50, choices=JOB_CATEGORY)
	discription=models.TextField(max_length=200)
	price=models.DecimalField( max_digits=5, decimal_places=2)
	# created_on=models.DateTimeField(auto_now_add=True)

class Review(models.Model):
	service=models.ForeignKey(Service,  on_delete=models.CASCADE)
	reating=models.CharField(choices=RATEING, max_length=50)
	body=models.TextField()
	# created_on=models.DateTimeField(auto_now_add=True)

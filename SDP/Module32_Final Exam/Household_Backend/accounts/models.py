from django.db import models
from django.contrib.auth.models import User
from phone_field import PhoneField

JOB_CATEGORY=(
	('electrician', 'Electrician'),
	('plumber', 'Plumber'),
	('internet', 'Internet Fixer'),
	('cleaner', 'House Cleaner'),
)

class BuyerProfile(models.Model):
	user=models.OneToOneField(User, verbose_name='buyer_profile', on_delete=models.CASCADE)
	phone=  PhoneField(blank=True, help_text='Contact phone number')
	account_type=models.CharField(default='buyer_account', max_length=50)
	total_bought=models.IntegerField(blank=True, null=True)

		

class SellerProfile(models.Model):
	user=models.OneToOneField(User,  on_delete=models.CASCADE)
	phone=  PhoneField(blank=True, help_text='Contact phone number')
	account_type=models.CharField(default='seller_account', max_length=20)
	service_category= models.CharField(choices=JOB_CATEGORY, max_length=50)
	completed_jobs=models.IntegerField(blank=True, null=True,)

	def __str__(self):
			return self.user.username
	

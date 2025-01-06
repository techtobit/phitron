from django.db import models
from accounts.models import SellerProfile
from django.utils.text import slugify

JOB_CATEGORY=(
	('electrician', 'Electrician'),
	('plumber', 'Plumber'),
	('internet', 'Internet Fixer'),
	('cleaner', 'Cleaner'),
	('delivery', 'Delivery'),
)

RATEING=(
	(1, '⭐'),
	(2, '⭐⭐'),
	(3, '⭐⭐⭐'),
	(4, '⭐⭐⭐⭐'),
	(5, '⭐⭐⭐⭐⭐'),
)

class Categorie(models.Model):
	category=models.CharField(max_length=12, choices=JOB_CATEGORY)
	slug=models.SlugField(max_length=12, choices=JOB_CATEGORY)

	def __str__(self):
		return self.category


class Service(models.Model):
	seller=models.ForeignKey(SellerProfile,  on_delete=models.CASCADE)
	service_title=models.CharField(max_length=50)
	categories= models.ForeignKey(Categorie, on_delete=models.CASCADE)
	discription=models.TextField(max_length=800)
	price=models.DecimalField( max_digits=5, decimal_places=2)
	image= models.ImageField(upload_to='services/media/')

	def __str__(self):
		return self.service_title


class Review(models.Model):
	service=models.ForeignKey(Service,  on_delete=models.CASCADE)
	rating=models.IntegerField(choices=RATEING)
	slug=models.SlugField(unique=False)
	body=models.TextField()
	created_on=models.DateTimeField(auto_now_add=True)

	def save(self, *args, **kwargs):
		if not self.slug:
			self.slug=slugify(self.rating)
		super().save(*args, **kwargs)

	def __str__(self):
		return f"{self.service} - {self.rating}"


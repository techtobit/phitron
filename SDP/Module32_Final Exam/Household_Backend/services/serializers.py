from rest_framework import serializers
from . import models
from accounts.models import SellerProfile
from django.contrib.auth.models import User

class CategorieSerialzer(serializers.ModelSerializer):
	class Meta:
		model= models.Categorie
		fields= ('category',)

class ServiceSerialzer(serializers.ModelSerializer):
	average_rating = serializers.FloatField(read_only=True)
	categories= CategorieSerialzer()
	seller= serializers.StringRelatedField()
	class Meta:
		model= models.Service
		fields = ['id', 'seller', 'service_title', 'categories', 'discription', 'price', 'image', 'average_rating']


class ReviewSerialzer(serializers.ModelSerializer):
	service = serializers.PrimaryKeyRelatedField(queryset=models.Service.objects.all())
	class Meta:
		model= models.Review
		fields= ('id', 'service', 'rating', 'body')
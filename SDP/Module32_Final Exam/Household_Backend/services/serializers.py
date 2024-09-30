from rest_framework import serializers
from . import models
from accounts.models import SellerProfile
from django.contrib.auth.models import User

class ServiceSerialzer(serializers.ModelSerializer):

	seller= serializers.StringRelatedField(many=False)
	class Meta:
		model= models.Service
		fields= '__all__'
		
		# def get_seller_username(self, obj):
		# 	return obj.seller.username 

		# def __init__(self, *args, **kwargs):
		# 	super(ServiceSerialzer, self).__init__(*args, **kwargs)
		# 	if self.context['request'].user.is_authenticated:
		# 		user=self.context['request'].user
		# 		seller_profile=SellerProfile.objects.filter(user=user)
		# 		self.fields['seller'].queryset=seller_profile


class ReviewSerialzer(serializers.ModelSerializer):
	service = serializers.PrimaryKeyRelatedField(queryset=models.Service.objects.all())
	class Meta:
		model= models.Review
		fields= '__all__'
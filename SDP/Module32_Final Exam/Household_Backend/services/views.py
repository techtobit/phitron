from django.shortcuts import render
from rest_framework import permissions
from rest_framework import viewsets
from django.contrib.auth.models import User
from . import serializers
from . import models
from accounts.models import SellerProfile

class ServiceViewSet(viewsets.ModelViewSet):
	queryset=models.Service.objects.all()
	serializer_class=serializers.ServiceSerialzer
	permission_classes = [permissions.AllowAny] 
	# def get_queryset(self):
	# 	user=self.request.user
	# 	seller=models.SellerProfile.objects.filter(user=user).first()
	# 	if seller:
	# 		new=models.Service.objects.filter(seller=seller)
	# 		return models.Service.objects.filter(seller=seller)
	# 	return models.Service.objects.none()

	# def perform_create(self, serializer):
	# 	seller=SellerProfile.objects.get(user=self.request.user)
	# 	print('seller-', seller.user)
	# 	serializer.save(seller=seller)
	


class ReviewViewSet(viewsets.ModelViewSet):
	queryset=models.Review.objects.all()
	serializer_class=serializers.ReviewSerialzer
	permission_classes = [permissions.IsAuthenticated] 
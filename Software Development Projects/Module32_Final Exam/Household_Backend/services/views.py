from django.shortcuts import render
from django.db.models import Avg
from rest_framework import permissions
from rest_framework import viewsets
from rest_framework import generics
from django.contrib.auth.models import User
from . import serializers
from . import models
from accounts.models import SellerProfile

class ServiceViewSet(viewsets.ModelViewSet):
	queryset=models.Service.objects.all()
	serializer_class=serializers.ServiceSerialzer
	permission_classes = [permissions.AllowAny]
	
	def list(self,request, *args, **kwargs):
		# filter category wise
		slug=self.kwargs.get('slug')
		if slug:
			self.queryset= self.queryset.filter(categories__slug=slug)
		
		# filter rating wise
		avg_rating= self.request.query_params.get('avg_rating', None)
		if avg_rating is not None:
			self.queryset=self.queryset.annotate(average_rating=Avg('review__rating')).filter(average_rating__gte=avg_rating)
		return super().list(request, *args, **kwargs)


class CategorieViewSet(viewsets.ModelViewSet):
	queryset=models.Categorie.objects.all()
	serializer_class=serializers.CategorieSerialzer
	permission_classes = [permissions.AllowAny]
	

class ReviewViewSet(viewsets.ModelViewSet):
	queryset=models.Review.objects.all()
	serializer_class=serializers.ReviewSerialzer
	permission_classes = [permissions.AllowAny]
	
	def get_queryset(self):
		queryset = super().get_queryset()
		service_id = self.request.query_params.get('service')
		rating = self.request.query_params.get('rating')

		print("Service ID:", service_id)
		print("Rating:", rating)
		
		if service_id is not None:
			queryset = queryset.filter(service=service_id) 
		if rating is not None: 
			queryset = queryset.filter(rating=rating) 
		return queryset
from django.shortcuts import render
# from rest_framework import 
from rest_framework import generics, viewsets 
from rest_framework.views import APIView
from rest_framework.response import Response
from django.contrib.auth.models import User
from . import serializers
from . import models

class BuyerRegistrationApiView(APIView):
	serializer_class= serializers.RegistrationSerializer

	def post(self, request):
		serializer=self.serializer_class(data=request.data)

		if serializer.is_valid():
			user=serializer.save()
			prolfe=models.BuyerProfile.objects.create(user=user, account_type='buyer')
			prolfe.save()
			return Response('Account Created')
		return Response(serializer.errors)

class SellerRegistrationApiView(APIView):
	serializer_class= serializers.RegistrationSerializer

	def post(self, request):
		serializer=self.serializer_class(data=request.data)

		if serializer.is_valid():
			user=serializer.save()
			prolfe=models.SellerProfile.objects.create(user=user, account_type='seller')
			prolfe.save()
			return Response('Account Created')
		return Response(serializer.errors)


class BuyerProfileViewSet(viewsets.ModelViewSet):
	queryset= models.BuyerProfile.objects.all()
	serializer_class= serializers.BuyerProfileSerializer
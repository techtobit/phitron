from django.shortcuts import render
from rest_framework import viewsets
from . import serializers
from . import models

class CartViewSet(viewsets.ModelViewSet):
	queryset= models.Cart.objects.all()
	serializer_class= serializers.CartSerializer
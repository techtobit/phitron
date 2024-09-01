from django.shortcuts import render
from rest_framework import viewsets
from . import serializers
from . import models

class ServiceViewSet(viewsets.ModelViewSet):
	queryset=models.Service.objects.all()
	serializer_class=serializers.ServiceSerialzer
	

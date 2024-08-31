from django.shortcuts import render
from rest_framework import viewsets
from . import models
from . import serializers
class PatientViewSets(viewsets.ModelViewSet):
	queryset= models.Patient.objects.all()
	serializer_class=serializers.PatientSerializer

from rest_framework import serializers
from . import models
from services.models import Service
from django.contrib.auth.models import User
from services.serializers import ServiceSerialzer
from rest_framework import permissions


class CartSerializer(serializers.ModelSerializer):
	customer = serializers.SlugRelatedField(
        slug_field='username',
        queryset=User.objects.all()
    )
	class Meta:
		model = models.Cart
		fields='__all__'


class OrderedSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.Ordered
		fields='__all__'
from rest_framework import serializers
from . import models
from services.models import Service
from services.serializers import ServiceSerialzer


class CartSerializer(serializers.ModelSerializer):
	customer = serializers.SlugRelatedField(
        slug_field='username',
        queryset=models.User.objects.all()
    )
	class Meta:
		model = models.Cart
		fields='__all__'

class OrderedSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.Ordered
		fields='__all__'
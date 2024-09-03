from rest_framework import serializers
from . import models
from services.models import Service
from services.serializers import ServiceSerialzer


class CartSerializer(serializers.ModelSerializer):
	# service= serializers.PrimaryKeyRelatedField(read_only=True)
	# service=ServiceSerializer(read_only=True)
	class Meta:
		model = models.Cart
		fields='__all__'

class OrderedSerializer(serializers.ModelSerializer):
	class Meta:
		model = models.Ordered
		fields='__all__'
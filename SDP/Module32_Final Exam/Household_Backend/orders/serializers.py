from rest_framework import serializers
from . import models
from services.models import Service
from services.serializers import ServiceSerialzer



# class ServiceSerializer(serializers.ModelSerializer):
#     class Meta:
#         model = models.Service
#         fields = '__all__' 


class CartSerializer(serializers.ModelSerializer):
	# service= serializers.PrimaryKeyRelatedField(read_only=True)
	# service=ServiceSerializer(read_only=True)
	class Meta:
		model = models.Cart
		fields='__all__'
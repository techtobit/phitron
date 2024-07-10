from rest_framework import serializers
from . import models

class PatientSerializer(serializers.ModelSerializer):
	# user = serializers.StringRelatedField(many=False)
	user = serializers.StringRelatedField(many=False)

	class Meta:
		model= models.Patient
		fields="__all__"
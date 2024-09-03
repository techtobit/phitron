from rest_framework import serializers
from . import models
from accounts.models import SellerProfile
class ServiceSerialzer(serializers.ModelSerializer):
	class Meta:
		model= models.Service
		fields="__all__"

		def __init__(self, *args, **kwargs):
			super(ServiceSerialzer, self).__init__(*args, **kwargs)
			if self.context['request'].user.is_authenticated:
				user=self.context['request'].user
				seller_profile=SellerProfile.objects.filter(user=user)
				self.fields['seller'].queryset=seller_profile

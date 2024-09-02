from rest_framework import serializers
from django.contrib.auth.models import User
from . import models

ACCOUNT_TYPE=(
    ('seller','Service Prover'),
    ('buyer', 'Client')
)

class RegistrationSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email','password']

    def save(self):
        username=self.validated_data['username']
        first_name=self.validated_data['first_name']
        last_name=self.validated_data['last_name']
        email=self.validated_data['email']
        password=self.validated_data['password']

        account=User(username=username, first_name=first_name, last_name=last_name, email=email,  password=password)
        account.set_password(password)
        account.save()
        return account



class BuyerProfileSerializer(serializers.ModelSerializer):
    user = serializers.PrimaryKeyRelatedField(queryset=User.objects.all())

    class Meta:
        model = models.BuyerProfile
        fields = ['user', 'phone',  'total_bought', 'total_spent']

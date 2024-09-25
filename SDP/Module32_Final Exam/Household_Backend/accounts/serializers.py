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

class UserLoginSerializer(serializers.Serializer):
    username = serializers.CharField(required = True)
    password = serializers.CharField(required = True)


class AllUsers(serializers.ModelSerializer):
    user = User.objects.all()

    class Meta:
        model = User
        fields = '__all__'


class UserRoleUpdateSerializer(serializers.ModelSerializer):
    class Meta:
        model = User
        fields=['is_staff', 'is_superuser']

class BuyerProfileSerializer(serializers.ModelSerializer):
    user=RegistrationSerializer()
    class Meta:
        model = models.BuyerProfile
        fields = ['user', 'phone', 'account_type']

    def create(self, validated_data):
        user_data = validated_data.pop('user')
        user =RegistrationSerializer().create(validated_data=user_data)
        
        # Automatically set account_type
        buyer_profile = models.BuyerProfile.objects.create(
            user=user, 
            account_type='buyer_account', 
            **validated_data
        )
        
        return buyer_profile


class SellerProfileSerializer(serializers.ModelSerializer):
    user= serializers.StringRelatedField(many=False)

    class Meta:
        model = models.SellerProfile
        fields = ['user', 'service_category', 'phone',  'completed_jobs']


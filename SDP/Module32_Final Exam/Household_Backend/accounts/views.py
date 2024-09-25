from django.shortcuts import render
# from rest_framework import 
from rest_framework import generics, viewsets 
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework.permissions import IsAuthenticated
from rest_framework.authentication import TokenAuthentication
from rest_framework import permissions,  status
from django.contrib.auth import authenticate, login
from rest_framework.authtoken.models import Token
from django.contrib.auth.models import User
from . import serializers
from . import models
from .permissions import IsAdminUser 

class BuyerRegistrationApiView(APIView):
	serializer_class= serializers.RegistrationSerializer

	def post(self, request):
		serializer=self.serializer_class(data=request.data)

		if serializer.is_valid():
			user=serializer.save()
			prolfe=models.BuyerProfile.objects.create(user=user)
			prolfe.save()
			return Response('Account Created')
		return Response(serializer.errors)

class SellerRegistrationApiView(APIView):
	serializer_class= serializers.RegistrationSerializer

	def post(self, request):
		serializer=self.serializer_class(data=request.data)

		if serializer.is_valid():
			user=serializer.save()
			prolfe=models.SellerProfile.objects.create(user=user)
			prolfe.save()
			return Response('Account Created')
		return Response(serializer.errors)


class UserLoginApiView(APIView):
    def post(self, request):
        serializer = serializers.UserLoginSerializer(data = self.request.data)
        if serializer.is_valid():
            username = serializer.validated_data['username']
            password = serializer.validated_data['password']

            user = authenticate(username= username, password=password)
            
            if user:
                token, _ = Token.objects.get_or_create(user=user)
                print(token)
                print(_)
                login(request, user)
                return Response({'token' : token.key, 'user_id' : user.id})
            else:
                return Response({'error' : "Invalid Credential"})
        return Response(serializer.errors)

class BuyerProfileViewSet(viewsets.ModelViewSet):
	queryset= models.BuyerProfile.objects.all()
	serializer_class= serializers.BuyerProfileSerializer
	permission_classes = [permissions.AllowAny] 
	# permission_classes = [IsAuthenticated]
	# def get_queryset(self):
	# 	return models.BuyerProfile.objects.filter(seller=self.request.user)
		
	# def perform_update(self, serializer):
	# 	serializer.save(user=self.request.user)

class SellerProfileViewSet(viewsets.ModelViewSet):
	queryset= models.SellerProfile.objects.all()
	serializer_class= serializers.SellerProfileSerializer
	# finding user by name insdead of id 
	def get_queryset(self):
		queryset = models.SellerProfile.objects.all()
		username = self.request.query_params.get('username', None)
		if username is not None:
			queryset = queryset.filter(user__username=username)
			return queryset

class AllUsersViewSet(viewsets.ModelViewSet):
	queryset= User.objects.all()
	serializer_class= serializers.AllUsers


class UserRoleUpdateViewSet(APIView):
	# authentication_classes = [TokenAuthentication] 
	# permission_classes = [ IsAuthenticated, IsAdminUser]  
	def patch(self, request, user_id):
		try:
			user = User.objects.get(pk=user_id)
		except User.DoesNotExist:
			return Response({"error": "User not found"}, status=status.HTTP_404_NOT_FOUND)
			
		serializer = serializers.UserRoleUpdateSerializer(user, data=request.data, partial=True)
		if serializer.is_valid():
			serializer.save()
			return Response(serializer.data, status=status.HTTP_200_OK)
		return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

# class UserRoleUpdateViewSet(APIView):
# 	permission_classes= [IsAdminUser]

# 	def patch(self, request, user_id):
# 		print('request-', request)
# 		print('userid-', user_id)
# 		try:
# 			user = User.objects.get(pk=user_id)
# 		except User.DoesNotExist:
# 			return Response({"error": "User not found"}, status=status.HTTP_404_NOT_FOUND)
		
# 		serializer= serializers.UserRoleUpdateSerializer(user, data=request.data, partial=True)
# 		if serializer.is_valid():
# 			serializer.save()
# 			return Response(serializer.data, status=status.HTTP_200_OK)
# 		return Response(serializer.error, status=status.HTTP_400_BAD_REQUEST)
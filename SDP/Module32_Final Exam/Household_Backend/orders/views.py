from django.shortcuts import render
from rest_framework import viewsets
from . import serializers
from . import models
from rest_framework.permissions import IsAuthenticated
from rest_framework.permissions import AllowAny

class CartViewSet(viewsets.ModelViewSet):
    queryset = models.Cart.objects.all()
    serializer_class = serializers.CartSerializer
    permission_classes = [AllowAny]  # Remove authentication requirement

    def perform_create(self, serializer):
        serializer.save()  # No need to pass `self.request.user`



# class CartViewSet(viewsets.ModelViewSet):
#     queryset = models.Cart.objects.all()
#     serializer_class = serializers.CartSerializer
#     permission_classes = [IsAuthenticated]

#     def perform_create(self, serializer):
#         serializer.save(customer=self.request.user)

class OrderedViewSet(viewsets.ModelViewSet):
	queryset= models.Ordered.objects.all()
	serializer_class= serializers.OrderedSerializer
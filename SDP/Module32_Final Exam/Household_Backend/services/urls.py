from django.contrib import admin
from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import ServiceViewSet


router=DefaultRouter()
router.register('', ServiceViewSet)
urlpatterns = [
	path('', include(router.urls)),
]

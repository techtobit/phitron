from django.contrib import admin
from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import ServiceViewSet, ReviewViewSet


router=DefaultRouter()
router.register('list', ServiceViewSet, basename='list'),
router.register('review', ReviewViewSet, basename='review')
urlpatterns = [
	path('', include(router.urls)),
	# path('', ServiceViewSet.as_view(), name='services')
]

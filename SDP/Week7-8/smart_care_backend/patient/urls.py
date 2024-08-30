from django.shortcuts import render
from django.urls import path, include
from  rest_framework import routers
from . import views

router=routers.DefaultRouter()
router.register('', views.PatientViewSets)

urlpatterns = [
		path('', include(router.urls) )
]

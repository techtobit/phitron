from django.urls import path
from . import views

urlpatterns = [
    path('', views.forms, name='feedback-form'),
    # path('', views.submitForm, name='feedback-form')
]

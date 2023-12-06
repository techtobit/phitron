from django.urls import path
from . import views

urlpatterns = [
    path('', views.forms, name='feedback-form'),
    path('django-form/', views.DjangoForm, name='django-form'),
    path('validity-check/', views.StudentForm, name='validity-check')
]

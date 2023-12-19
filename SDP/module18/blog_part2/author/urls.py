from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('add/', views.add_author, name='add_author'),
    path('register/', views.register , name='register'),
    path('login/', views.user_login, name='user_login'),
]

from django.urls import path
from . import views

urlpatterns = [
    path('', views.navHome),
    path('about/', views.about, name='about'),
    path('contact/', views.contact, name='contact'),
]

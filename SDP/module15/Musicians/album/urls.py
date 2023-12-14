from django.urls import path
from . import views

urlpatterns = [
    path('add/', views.add_album, name='add_album')
]

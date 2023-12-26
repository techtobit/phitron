from django.urls import path
from . import views

urlpatterns = [
    path('set/', views.set_cookie, name='set_cookie' )
]

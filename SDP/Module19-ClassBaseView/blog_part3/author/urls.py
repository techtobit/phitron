from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [
    path('add/', views.add_author, name='add_author'),
    path('register/', views.register , name='register'),
    # path('login/', views.user_login, name='user_login'),
    path('login/', views.UserLoginView.as_view(), name='user_login'),
    path('logout/', views.session_logout, name='logout'),
    path('profile/', views.profile, name='profile'),
    path('update_profile/', views.edit_profile, name='update_profile'),
    path('profile/change_pass', views.pass_change, name='change_pass'),
]

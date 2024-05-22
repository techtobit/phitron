from django.urls import path
from .views import UserRegistrationView, UserLoginView, UserLogOutView, UserUpdateView
urlpatterns = [
    path('register/', UserRegistrationView.as_view(), name='register'),
    path('login/', UserLoginView.as_view(), name='login'),
    path('profile/',UserUpdateView.as_view(), name='profile'),
    path('logout/',UserLogOutView.as_view(), name='logout'),
]
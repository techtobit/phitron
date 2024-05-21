from django.urls import path
from .views import UserRegistrationView, UserLoginView, UserLogOutView
urlpatterns = [
    path('register/', UserRegistrationView.as_view(), name='register'),
    path('login/', UserLoginView.as_view(), name='login'),
    path('logout/',UserLogOutView.as_view(), name='logout'),
]
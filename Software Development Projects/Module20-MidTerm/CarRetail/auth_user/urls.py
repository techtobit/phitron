from django.urls import path
from . import views

urlpatterns = [
    path('register/', views.RegisterView.as_view(), name='register'),
    path('login/', views.UserLogInView.as_view(), name='login'),
    path('logout/', views.UserLogOutView.as_view(), name='logout'),
    path('update_profile/', views.UpdateProfileView.as_view(), name='update_profile'),
]

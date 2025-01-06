from django.urls import path
from . import views

urlpatterns = [
    path('register/', views.RegisterView.as_view() , name='register'),
    # path('register/', views.register , name='register'),
    
    path('login/', views.UserLoginView.as_view(), name='user_login'),
    path('logout/', views.SessionLogoutView.as_view(), name='logout'),
]

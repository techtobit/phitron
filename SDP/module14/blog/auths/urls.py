from django.urls import path
from . import views

urlpatterns = [
    path('singup/', views.signup, name='signup'),
    path('login/', views.user_login, name='login'),
    path('profile/', views.profile, name='profile'),
    path('logout/', views.logout_view, name='logout')
]

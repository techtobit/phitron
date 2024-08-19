from django.urls import path
from .views import RegistrationsView, LoginView, LogOutView, ProfileView

urlpatterns = [
		path('register/', RegistrationsView.as_view(), name='register'),
		path('login/', LoginView.as_view(), name='login'),
		path('logout/', LogOutView.as_view(), name='logout'),
		path('profile/', ProfileView, name='profile')
		# path('profile/', ProfileView.as_view(), name='profile')
]

from django.urls import path
from .views import RegistrationsView, LoginView

urlpatterns = [
		path('register/', RegistrationsView.as_view(), name='register'),
		path('login/', LoginView.as_view(), name='login')
]

from django.urls import path
from .views import SingUp, RegistrationsView, LoginView

urlpatterns = [
		path('', SingUp.as_view()),
		path('register/', RegistrationsView.as_view(), name='register'),
		path('login/', LoginView.as_view(), name='login')
]

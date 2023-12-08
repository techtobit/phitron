from django.urls import path
from . import views

urlpatterns = [
    path('', views.forms, name='feedback-form'),
    path('django-form/', views.DjangoForm, name='django-form'),
    path('validity-check/', views.StudentForm, name='validity-check'),
    path('password-validity-check/', views.PasswordValidation, name='password-validity-check'),
    path('model-data', views.DisplayData, name='model-data'),
    path('delete/<int:roll>', views.deleteStudent, name='delete-student')
]

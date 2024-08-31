from django.urls import path
# from .view import contact
from . import view

urlpatterns = [
    path('courses/', view.courses),
]


from django.contrib import admin
from django.urls import path, include
# from .view import contact
from . import view

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', view.home ),
    path('first_app/', include('first_app.urls') ),
    path('contact/', view.contact )
]


from django.contrib import admin
from django.urls import path, include
from . import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.home, name='home'),

    path('posts/', include('posts.urls')),
    path('profiles/', include('profiles.urls')),
    path('categories/', include('categories.urls')),
    
]

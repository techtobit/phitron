
from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),

    path('about/', include('author.urls')),
    path('posts/', include('posts.urls')),
    path('profiles/', include('profiles.urls')),
    path('categories/', include('categories.urls')),
]

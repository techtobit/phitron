
from django.contrib import admin
from django.urls import path, include
from Core.views import Home


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', Home.as_view(), name='home'),
    path('auth/', include('User.urls')),
    path('lms/', include('Books.urls')),
]

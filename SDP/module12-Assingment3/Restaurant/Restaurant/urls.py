
from django.contrib import admin
from django.urls import path, include
from . import views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.home, name='home'),
    # path('', views.hero, name='home'),
    path('about/', include('about.urls')),
    path('meals/', include('meals.urls'))
]

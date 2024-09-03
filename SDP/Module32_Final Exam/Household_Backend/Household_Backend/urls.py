
from django.contrib import admin
from django.urls import path, include
from .views import Home
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', Home.as_view(), name='home'),
    path('service/', include('services.urls')),
    path('orders/', include('orders.urls')),
    path('auth/', include('accounts.urls'))
]


from django.contrib import admin
from django.conf import settings
from django.urls import path, include
from .views import Home
from django.conf.urls.static import static
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', Home.as_view(), name='home'),
    path('services/', include('services.urls')),
    path('orders/', include('orders.urls')),
    path('auth/', include('accounts.urls'))
]+ static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

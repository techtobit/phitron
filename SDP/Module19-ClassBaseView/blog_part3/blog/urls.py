
from django.contrib import admin
from django.urls import path, include
from . import views
from django.conf.urls.static import static
from django.conf import settings

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.home, name='home'),
    path('category/<slug:category_slug>/', views.home, name='category_wise_post'),
    path('author/', include('author.urls')),
    path('posts/', include('posts.urls')),
    path('categories/', include('categories.urls')),
    path('cookies/', include('cookies.urls')),

]
urlpatterns +=static(settings.MEDIA_URL, document_root = settings.MEDIA_ROOT)


from django.contrib import admin
from django.urls import path, include
from . import views
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.home),
    path('tasklist/', include('tasklist.urls')),
    path('categories/', include('categories.urls')),
    path('task/', views.show_task, name='show_task'),
    path('tasks/', views.show_taskby_categorie, name='show_taskby_categorie'),
]

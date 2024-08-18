from django.urls import path
from . import views

urlpatterns = [
		# path('', Home.as_view(), name='home'),
		path('', views.Home, name='home'),
		path('category/<slug:ctg_slug>/', views.Home, name='catgory_wise_book'),
]

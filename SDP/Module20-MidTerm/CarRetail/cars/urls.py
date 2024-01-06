from django.urls import path
from . import views

urlpatterns = [
    path('add_cars/', views.AddCar.as_view(), name='add_cars'),
    path('details/<int:id>/', views.DetailPostView.as_view(), name='detail_post'),
]

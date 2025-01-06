from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router=DefaultRouter()
router.register('cart', views.CartViewSet, basename='cart')
router.register('order', views.OrderedViewSet, basename='order')

urlpatterns = [
		path('', include(router.urls))
]


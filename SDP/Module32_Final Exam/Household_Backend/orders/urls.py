from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router=DefaultRouter()
router.register('', views.CartViewSet)
router.register('o', views.OrderedViewSet, basename='order')

urlpatterns = [
		path('', include(router.urls))
]


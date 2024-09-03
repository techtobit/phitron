from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router=DefaultRouter()
router.register(r'buyer_profile', views.BuyerProfileViewSet, basename='buyer_profile')
router.register('seller_profile', views.SellerProfileViewSet, basename='seller_profile')

urlpatterns = [
		path('', include(router.urls)),
		path('buyer_register/', views.BuyerRegistrationApiView.as_view(), name='buyer_register'),
		path('seller_register/', views.SellerRegistrationApiView.as_view(), name='seller_register'),
]

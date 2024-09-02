from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router=DefaultRouter()
router.register('buyer_profile/', views.BuyerProfileViewSet)

urlpatterns = [
		path('', include(router.urls)),
		path('buyer_register/', views.BuyerRegistrationApiView.as_view(), name='buyer_register'),
		path('seller_register/', views.SellerRegistrationApiView.as_view(), name='seller_register'),
]

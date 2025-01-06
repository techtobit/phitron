from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

router=DefaultRouter()
router.register('buyer_profile', views.BuyerProfileViewSet, basename='buyer_profile')
router.register('seller_profile', views.SellerProfileViewSet, basename='seller_profile')
router.register('users', views.AllUsersViewSet, basename='users')


urlpatterns = [
		path('', include(router.urls)),
		path('buyer_register/', views.BuyerRegistrationApiView.as_view(), name='buyer_register'),
		path('seller_register/', views.SellerRegistrationApiView.as_view(), name='seller_register'),
		path('login/', views.UserLoginApiView.as_view(), name='seller_register'),
		path('users/<int:user_id>/update_role/', views.UserRoleUpdateViewSet.as_view(), name='update_user_role'),
]

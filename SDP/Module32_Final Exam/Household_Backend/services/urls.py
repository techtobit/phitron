from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import ServiceViewSet, ReviewViewSet, CategorieViewSet

router = DefaultRouter()
router.register('list', ServiceViewSet, basename='list')
router.register('review', ReviewViewSet, basename='review')
router.register('categories', CategorieViewSet, basename='categories')

service_list = ServiceViewSet.as_view({'get': 'list'})
review_list=ReviewViewSet.as_view({'get': 'list'})

urlpatterns = [
    path('', include(router.urls)), 
    path('list/', service_list, name='services_list'),  
    path('list/category/<slug:slug>/', service_list, name='services_list_by_slug') ,
    path('review/rating/<slug:rating>/', review_list, name='reviews_by_rating'),
]

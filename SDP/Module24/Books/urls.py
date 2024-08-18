from django.urls import path
from .views import AddBooksView, AddCategoryView

urlpatterns = [
		path('addBook/', AddBooksView.as_view(), name='add_book'),
		path('addCategory/', AddCategoryView.as_view(), name='add_category')
]

from django.urls import path
from .views import AddBooksView, AddCategoryView, BookDetialsView

urlpatterns = [
		path('addBook/', AddBooksView.as_view(), name='add_book'),
		path('addCategory/', AddCategoryView.as_view(), name='add_category'),
		path('bookDetials/<int:id>/', BookDetialsView.as_view(), name='book_detials')
]

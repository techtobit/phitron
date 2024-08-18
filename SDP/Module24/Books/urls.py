from django.urls import path

from .views import AddBooksView
urlpatterns = [
		path('addBook/', AddBooksView.as_view(), name='addBook')
]

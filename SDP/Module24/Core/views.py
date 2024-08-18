from django.shortcuts import render
from django.views import View
from django.views.generic import TemplateView
from Books.models import Books, Categories
from django.db.models import Count
# Create your views here.

# class Home(TemplateView):
# 	template_name = 'index.html'

# def home(request):
# 	data = 'hello'
# 	return render(request, 'index.html', {'data':data})

def Home(request, ctg_slug=None):
	print(ctg_slug)
	books = Books.objects.all()
	if ctg_slug is not None:
		ctg_book= Categories.objects.get(slug=ctg_slug)
		book = Books.objects.filter(category=ctg_book)
	
	categories = Categories.objects.annotate(book_post_count=Count('books'))
	return render(request, 'index.html', {'books':books, 'categories':categories})


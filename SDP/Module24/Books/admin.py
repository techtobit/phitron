from django.contrib import admin
from .models import Books , BookCategory

# Register your models here.
admin.site.register(Books)
admin.site.register(BookCategory)
from django.contrib import admin
from .models import Books, Categories, Reviews

# Register your models here.
admin.site.register(Books)
admin.site.register(Categories)
admin.site.register(Reviews)
from django.contrib import admin
from .models import Books, Categories, Reviews

class CategoryAdmin(admin.ModelAdmin):
    prepopulated_fields = {'slug': ('category',)}
    list_display = ['category', 'slug']

admin.site.register(Categories, CategoryAdmin)
admin.site.register(Books)
admin.site.register(Reviews)

from django.contrib import admin
from. import models



class CategorieAdmin(admin.ModelAdmin):
		# prepopulated_fields = {'slug': ('category',)}
		list_display=(
			'category',
			'slug',
		)
class ServiceAdmin(admin.ModelAdmin):
		list_display=(
			'seller',
			'service_title',
			'price',
		)

class ReviewAdmin(admin.ModelAdmin):
		list_display=(
			'service',
			'rating',
			'body',
			# 'created_on',
		)
admin.site.register(models.Categorie, CategorieAdmin)
admin.site.register(models.Service, ServiceAdmin)
admin.site.register(models.Review, ReviewAdmin)


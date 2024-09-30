from django.contrib import admin
from. import models

class ServiceAdmin(admin.ModelAdmin):
		list_display=(
			'seller',
			'service_title',
			'category',
			'price',
			# 'created_on',
		)

class ReviewAdmin(admin.ModelAdmin):
		list_display=(
			'service',
			'rating',
			'body',
			# 'created_on',
		)
admin.site.register(models.Service, ServiceAdmin)
admin.site.register(models.Review, ReviewAdmin)


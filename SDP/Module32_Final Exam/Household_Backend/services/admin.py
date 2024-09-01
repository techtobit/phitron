from django.contrib import admin
from. import models

class ServiceAdmin(admin.ModelAdmin):
		list_display=(
			'name',
			'category',
			'price',
			'created_on',
		)
admin.site.register(models.Service, ServiceAdmin)


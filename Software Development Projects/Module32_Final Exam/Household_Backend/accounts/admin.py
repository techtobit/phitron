from django.contrib import admin
from . import models


class BuyerProfileAdmin(admin.ModelAdmin):
		list_display=(
			'user',
			'phone',
			'total_bought',
			'account_type',
		)

class SellerProfileAdmin(admin.ModelAdmin):
		list_display=(
			'user',
			'phone',
			'service_category',
			'completed_jobs',
		)

admin.site.register(models.BuyerProfile, BuyerProfileAdmin)
admin.site.register(models.SellerProfile, SellerProfileAdmin)

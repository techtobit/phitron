from django.contrib import admin
from .models import Cart, Ordered

# class CartAdmin(admin.ModelAdmin):
		# list_display=(
		# 	# 'customer',
		# 	'price',
		# 	'service'
		# 	)

class OrderedAdmin(admin.ModelAdmin):
		list_display=(
			'cart',
			# 'address'
			)
admin.site.register(Cart, )
admin.site.register(Ordered,OrderedAdmin)


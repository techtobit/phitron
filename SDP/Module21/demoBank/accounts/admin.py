from django.contrib import admin
from . import models

# Register your models here.
admin.site.register(models.UserBankAccount)
admin.site.register(models.UserAddress)

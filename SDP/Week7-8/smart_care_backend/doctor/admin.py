from django.contrib import admin
from . import models
# Register your models here.
admin.site.register(models.Doctor)
admin.site.register(models.Specialization)
admin.site.register(models.Designation)
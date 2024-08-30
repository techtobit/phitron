from django.contrib import admin
from . import models
# Register your models here.
admin.site.register(models.Patient)
admin.site.register(models.Review)
admin.site.register(models.Appointment)

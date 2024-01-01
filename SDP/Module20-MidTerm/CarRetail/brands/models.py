from django.db import models

class Brand(models.Model):
    brand_anme = models.CharField(max_length=20)

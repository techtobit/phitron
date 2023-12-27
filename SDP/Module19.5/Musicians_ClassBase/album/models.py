from django.db import models
from musician.models import Musician
from django.core.validators import MinValueValidator, MaxValueValidator
from datetime import date
# Create your models here.


class Album(models.Model):
    album_name = models.CharField(max_length=20)
    musician = models.ForeignKey(Musician, on_delete=models.CASCADE)
    date = models.DateField(("Date"), default=date.today)
    rateing = models.IntegerField(default=1,validators=[MinValueValidator(1), MaxValueValidator(5)])
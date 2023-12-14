from django.db import models
from musician.models import Musician
from django.core.validators import MinValueValidator, MaxValueValidator


# Create your models here.
class Album(models.Model):
    album_name = models.CharField(max_length=20)
    musician = models.ForeignKey(Musician, on_delete=models.CASCADE)
    album_release_data= models.DateTimeField()
    rateing = models.IntegerField(default=1, validators=[MinValueValidator(1), MaxValueValidator(5)])
    discription = models.TextField()

    def __str__(self) -> str:
        return f'{self.album_name} | {self.musician}'

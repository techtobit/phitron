from django.db import models
from tasklist.models import TaskList
# Create your models here.

class Categorie(models.Model):
    category_name = models.CharField(max_length=20)
    tasks = models.ManyToManyField(TaskList)

    def __str__(self) -> str:
        return f'{self.category_name}'


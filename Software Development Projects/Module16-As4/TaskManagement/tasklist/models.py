from django.db import models
from categories.models import Categorie

# Create your models here.


class TaskList(models.Model):
    taskTitle = models.CharField(max_length=20)
    taskDescription = models.CharField(max_length=80)
    is_completed = models.BooleanField(default=False)
    assign_date = models.DateField()
    categorie = models.ManyToManyField(Categorie)


    def __str__(self) -> str:
        return f'{self.taskTitle} | {self.assign_date}'

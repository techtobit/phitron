from django.db import models

# Create your models here.


class TaskList(models.Model):
    taskTitle = models.CharField(max_length=20)
    taskDescription = models.CharField(max_length=80)
    is_completed = models.BooleanField(default=False)
    assign_date = models.DateField(auto_now_add=True)

    def __str__(self) -> str:
        return f'{self.taskTitle} | {self.is_completed} | {self.assign_date}'

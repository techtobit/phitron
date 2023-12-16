from django.db import models

class Categorie(models.Model):
    category_name = models.CharField(max_length=20)

    def __str__(self) -> str:
        return f'{self.category_name}'

from django.db import models


# Create your models here.
class Musician(models.Model):
    first_name = models.CharField(max_length=20)
    last_name = models.CharField(max_length=20)
    email = models.EmailField(max_length=45)
    phone_number = models.CharField(max_length=15, help_text="Input phone number")
    instrument_type = models.CharField(max_length=20)

    def __str__(self):
        return f'{self.first_name} | {self.phone_number}'
    
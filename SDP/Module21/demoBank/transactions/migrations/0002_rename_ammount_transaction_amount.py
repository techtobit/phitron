# Generated by Django 5.0.6 on 2024-05-23 16:19

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('transactions', '0001_initial'),
    ]

    operations = [
        migrations.RenameField(
            model_name='transaction',
            old_name='ammount',
            new_name='amount',
        ),
    ]

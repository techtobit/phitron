# Generated by Django 4.2.15 on 2024-09-03 17:59

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('services', '0006_review'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='review',
            name='service',
        ),
    ]

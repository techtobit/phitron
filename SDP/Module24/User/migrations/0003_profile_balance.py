# Generated by Django 4.2.15 on 2024-08-19 13:49

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('User', '0002_profile_delete_account'),
    ]

    operations = [
        migrations.AddField(
            model_name='profile',
            name='balance',
            field=models.IntegerField(default=100),
            preserve_default=False,
        ),
    ]

# Generated by Django 4.2.15 on 2024-08-20 22:34

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Books', '0010_alter_reviews_book'),
    ]

    operations = [
        migrations.AlterField(
            model_name='reviews',
            name='rate',
            field=models.CharField(choices=[('1', '⭐'), ('2', '⭐⭐'), ('3', '⭐⭐⭐'), ('4', '⭐⭐⭐⭐'), ('5', '⭐⭐⭐⭐⭐')], default=1, max_length=10),
        ),
    ]
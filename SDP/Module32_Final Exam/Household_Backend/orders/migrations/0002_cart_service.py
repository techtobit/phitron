# Generated by Django 4.2.11 on 2024-11-07 16:36

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('services', '0002_alter_categorie_category_alter_categorie_slug'),
        ('orders', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='cart',
            name='service',
            field=models.ForeignKey(default=22, on_delete=django.db.models.deletion.CASCADE, to='services.service'),
            preserve_default=False,
        ),
    ]
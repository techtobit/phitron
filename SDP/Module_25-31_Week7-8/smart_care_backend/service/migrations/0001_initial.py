# Generated by Django 4.2.15 on 2024-08-28 20:00

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Service',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('name', models.CharField(max_length=50)),
                ('discription', models.TextField(max_length=150)),
                ('imgae', models.ImageField(upload_to='service/media')),
            ],
        ),
    ]

# Generated by Django 4.2.15 on 2024-08-18 14:03

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Books', '0002_bookcategory_alter_books_price_books_categories'),
    ]

    operations = [
        migrations.AlterField(
            model_name='books',
            name='categories',
            field=models.ManyToManyField(to='Books.bookcategory'),
        ),
    ]
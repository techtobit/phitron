# Generated by Django 4.2.15 on 2024-09-02 16:58

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('accounts', '0006_remove_buyerprofile_bio_and_more'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='buyerprofile',
            name='total_spent',
        ),
        migrations.RemoveField(
            model_name='sellerprofile',
            name='bio',
        ),
        migrations.RemoveField(
            model_name='sellerprofile',
            name='total_bought',
        ),
        migrations.RemoveField(
            model_name='sellerprofile',
            name='total_jobs',
        ),
        migrations.RemoveField(
            model_name='sellerprofile',
            name='total_spent',
        ),
        migrations.AddField(
            model_name='sellerprofile',
            name='completed_jobs',
            field=models.IntegerField(blank=True, null=True),
        ),
        migrations.AddField(
            model_name='sellerprofile',
            name='service_category',
            field=models.CharField(choices=[('electrician', 'Electrician'), ('plumber', 'Plumber'), ('internet', 'Internet Fixer'), ('cleaner', 'House Cleaner')], default=1, max_length=50),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='buyerprofile',
            name='account_type',
            field=models.CharField(default=1, max_length=50),
            preserve_default=False,
        ),
        migrations.DeleteModel(
            name='Profile',
        ),
    ]

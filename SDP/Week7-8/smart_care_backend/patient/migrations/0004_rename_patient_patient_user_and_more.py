# Generated by Django 4.2.15 on 2024-08-30 01:27

from django.db import migrations, models
import django.db.models.deletion
import django.utils.timezone


class Migration(migrations.Migration):

    dependencies = [
        ('doctor', '0003_availabletime_designation_specialization_and_more'),
        ('patient', '0003_review_appointment'),
    ]

    operations = [
        migrations.RenameField(
            model_name='patient',
            old_name='patient',
            new_name='user',
        ),
        migrations.RenameField(
            model_name='review',
            old_name='doctor_for',
            new_name='doctor',
        ),
        migrations.RenameField(
            model_name='review',
            old_name='patient',
            new_name='reviewer',
        ),
        migrations.AddField(
            model_name='appointment',
            name='appointment_status',
            field=models.CharField(choices=[('Completed', 'Completed'), ('Pending', 'Pending'), ('Running', 'Running')], default='Pending', max_length=50),
        ),
        migrations.AddField(
            model_name='appointment',
            name='cancel',
            field=models.BooleanField(default=False),
        ),
        migrations.AddField(
            model_name='review',
            name='created',
            field=models.DateField(auto_now_add=True, default=django.utils.timezone.now),
            preserve_default=False,
        ),
        migrations.RemoveField(
            model_name='appointment',
            name='doctor',
        ),
        migrations.RemoveField(
            model_name='appointment',
            name='patient',
        ),
        migrations.AlterField(
            model_name='appointment',
            name='time',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to='doctor.availabletime'),
        ),
        migrations.AddField(
            model_name='appointment',
            name='doctor',
            field=models.ForeignKey(default=11, on_delete=django.db.models.deletion.CASCADE, related_name='doctor_apointment', to='doctor.doctor'),
            preserve_default=False,
        ),
        migrations.AddField(
            model_name='appointment',
            name='patient',
            field=models.ForeignKey(default=1, on_delete=django.db.models.deletion.CASCADE, related_name='patient_apointment', to='patient.patient'),
            preserve_default=False,
        ),
    ]

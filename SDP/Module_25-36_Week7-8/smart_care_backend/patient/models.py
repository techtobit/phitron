from django.db import models
from django.contrib.auth.models import User
from doctor.models import Doctor, AvailableTime
# Create your models here.

GENDER=(
	('male', 'MALE'),
	('fmale', 'FMALE'),
)

APPOINTMENT_STATUS = [
    ('Completed', 'Completed'),
    ('Pending', 'Pending'),
    ('Running', 'Running'),
]

APPOINTMENT_TYPE=(
	('online', 'Online'),
	('offline', 'Offline'),
)


RATE = (
	('1', '⭐'),
	('2', '⭐⭐'),
	('3', '⭐⭐⭐'),
	('4', '⭐⭐⭐⭐'),
	('5', '⭐⭐⭐⭐⭐'),
)


class Patient(models.Model):
	user=models.OneToOneField(User, related_name='patient', on_delete=models.CASCADE)
	phone=models.CharField( max_length=12)
	age=models.IntegerField()
	gender=models.CharField(choices=GENDER, max_length=10)
	address=models.CharField( max_length=12)

	def __str__(self):
			return f'{self.user} - {self.phone}'
	

class Review(models.Model):
	reviewer=models.ForeignKey(Patient, on_delete=models.CASCADE)
	doctor=models.ForeignKey(Doctor, related_name='doctor_review', on_delete=models.CASCADE)
	rateing=models.CharField(choices=RATE, max_length=12)
	text= models.TextField(max_length=50)
	created=models.DateField(auto_now_add=True)

class Appointment(models.Model):
	patient= models.ForeignKey(Patient, related_name='patient_apointment', on_delete=models.CASCADE)
	doctor= models.ForeignKey(Doctor, related_name='doctor_apointment', on_delete=models.CASCADE)
	appointment_type= models.CharField(choices=APPOINTMENT_TYPE, max_length=10)
	appointment_status=models.CharField(choices=APPOINTMENT_STATUS, max_length=50, default="Pending")
	symptoms= models.CharField( max_length=50)
	time=models.OneToOneField(AvailableTime, on_delete=models.CASCADE)
	cancel=models.BooleanField(default=False)

	def __str__(self):
		return f"Doctor : {self.doctor.user.first_name} , Patient : {self.patient.user.first_name}"
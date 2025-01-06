from django.db import models
from accounts.models import UserBankAccount
from .constant import TRANSACTION_TYPE

class Transaction(models.Model):
	account = models.ForeignKey(UserBankAccount, related_name='transactions', on_delete=models.CASCADE)
	
	amount = models.DecimalField(max_digits=12, decimal_places=2)
	balance_after_transaction = models.DecimalField(max_digits=12, decimal_places=2)
	transaction_type = models.IntegerField(choices=TRANSACTION_TYPE, null=True)
	timestamp = models.DateTimeField( auto_now_add=True)
	loan_approve = models.BooleanField(default=False)

	class Meta:
		ordering = ['timestamp']

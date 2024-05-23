from django.forms import forms
from .models import Transaction

class TransactionForm(forms.ModelForm):
	class Meta:
		model = Transaction
		fields = [
			'amount',
			'transaction_type'
		]
	
	def __init__(self, *args, **kwargs):
		self.user_account = kwargs.pop('account')
		super().__init__(slef, *args, **kwargs)
		self.fields['transaction_type'].disabled = True
		slef.fields['transaction_type'].widget = forms.HiddenInput()

	def save(self, commit=True):
		self.instance.account = self.user_account
		self.instance.balance_after_transaction = self.account.balance

		return super().save()

class DepositFrom(Transaction):
	def clean_amount(self):
		min_deposit_amount=100
		amount = self.cleand_data.get('amount')
		if amount < min_deposit_amount:
			raise forms.ValidationError(
				f'You need to deposit at least $ {min_deposit_amount}'
			)
		return amount
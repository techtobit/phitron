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
		#check youtube video about pop
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

class WithdrawForm(Transaction):
	def clean_amount(self):
		account = self.account
		min_withdraw_ammount = 500
		max_withdraw_ammount = 25000
		balance = account.balance
		amount = self.cleaned_data.get('amount')
		if amount < min_withdraw_ammount:
			raise forms.ValidationError(
				f'You can withdraw at least ${min_withdraw_ammount}'
			)
		if amount > balance:
			raise forms.ValidationError(
				f'Insufficient Balance'
			)
		if amount > max_withdraw_ammount :
			raise forms.ValidationError(
				f'You cannot widthdraw more then $ {max_withdraw_ammount}'
			)
		return amount

class LoanRequestFrom(Transaction):
	def clean_amount(self):
		max_eligible_loan = account.balance * 2
		amount = self.cleaned_data.get('amount')
		if amount > max_eligible_loan:
			raise forms.ValidationError(
				f'Your eligible lone limit is ${max_eligible_loan}'
			)
		return amount

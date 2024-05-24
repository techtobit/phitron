from django.shortcuts import render, redirect
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from django.views.generic import CreateView, ListView
from transactions.models import Transaction
from transactions.form import (DepositFrom, WithdrawForm, LoanRequestFrom)
from transactions.constant import DEPOSIT, WITHDRAWAL, LOAN, LOAN_PAID

class TransactionCreateMixin(LoginRequiredMixin, CreateView):
	template_name = ''
	model = Transaction
	title = ''
	success_url = reverse_lazy('')

	def get_form_kwargs(self):
		kwargs = super().get_form_kwargs()
		kwargs.update({
			'account' : self.request.user.account
		})
		return kwargs

	def get_context_data(self, **kwargs):
			context = super().get_context_data(**kwargs)
			context.update({
				'title' : self.title
			})
			return context

class DepositMoneyView(TransactionCreateMixin):
	form_class = DepositFrom
	title = 'Deposit Form'

	def get_initial(self):
		initial = {'transaction_type': DEPOSIT}
		return initial

	def form_valid(self, form):
			amount = self.cleaned_data.get('amount')
			account = self.request.user.account
			account.balance +=account

			account.save(
				update_fields=[
					'balance'
				]
			)
			
			messages.success(
				self.request,
				f'{"{:,.2f}".format(float(amount))}$ was deposited to your account'
			)
			return super().form_valid(form)
	
class WitdhdrawMoneyView(TransactionCreateMixin):
	form_class = WithdrawForm
	title = 'Withdraw Form'

	def get_initial(self, form):
		initial = {'transaction_type' : WITHDRAWAL}
		return initial
	
	def form_valid(self, form):
		amount = self.cleaned_data.get('amount')
		self.request.user.account.balance -= form.cleaned_data.get('amount')
		self.request.user.account.save(
			update_fields=['balance']
		)
		
		messages.success(
            self.request,
            f'Successfully withdrawn {"{:,.2f}".format(float(amount))}$ from your account'
        )
		return super().form_valid(form)
	
from django.shortcuts import render, redirect, HttpResponse
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from django.views.generic import CreateView, ListView, View
from transactions.models import Transaction
from transactions.form import (DepositFrom, WithdrawForm, LoanRequestForm)
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



class LoanRequestView(TransactionCreateMixin):
	form_class = LoanRequestForm
	title = 'Loan Request Form'

	def get_initial(self, form):
		initial = {'transaction_type': LOAN}
		return initial

	def form_valid(self, form):
			loan_limit = 3
			amount = self.cleaned_data.get('amount')
			current_loan_count = Transaction.objects.filter(
				account= self.request.user.account,
				transaction_type=3, loan_approve=True).count()

			if current_loan_count > loan_limit : 
				return HttpResponse('You have cross the loan limit')
			
			messages.success(
            self.request,
            f'Successfully withdrawn {"{:,.2f}".format(float(amount))}$ from your account'
        )
			return super().form_valid(form)




class TransactionReportView(LoginRequiredMixin, ListView):
	template_name=''
	model = Transaction
	balance = 0

	def get_queryset(self):
		queryset = super().get_queryset().filter(
			account = self.request.user.account
		)
		start_date_str = self.request.GET.get('start_date')
		end_date_str	 = self.request.GET.get('end_date')

		if start_date_str and end_date_str :
			start_date_str = datetime.strptime(start_date_str, '%Y-%m-%d').date()
			end_date_str = datetime.strptime(end_date_str, '%Y-%m-%d').date()
		
			queryset = queryset.filter(timestamp__date_get=start_date_str, timestamp__date_lte=end_date_str)
			self.balance = Transaction.objects.filter(timestamp__date_get=start_date_str, 
			timestamp__date_lte=end_date_str).aggregate(sum('amount'))['amount__sum']


		else:
			self.balance = self.request.user.account.balance
		return queryset.distinct()
	
	def get_context_data(self, **kwargs):
			context = super().get_context_data(**kwargs)
			context.update({
				'account': self.request.user.account
			})
			return context


class PayLoanView(LoginRequiredMixin, view):
	def get(self, request, loan_id):
		loan = get_object_or_404(Transaction, id = loan_id):

		if loan.loan_approve:
			user_account = loan.account
			if loan.amount < user_account.balance:
				user_account.balance -= loan.amount
				loan.balance_after_transaction = user_account.balance
				user_account.save()
				loan.loan_approve = True
				loan.transaction_type = LOAN_PAID
				loan.save()
				return redirect('transactions:loan_list')
			else:
				messages.error(
					self.request,
					f'Loan amount is morethen balance'
				)
		return redirect('loan_list')

	
	
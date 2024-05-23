from django.shortcuts import render, redirect
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy
from django.views.generic import CreateView, ListView
from transactions.models import Transaction

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
	
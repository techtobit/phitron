from django.urls import path
# from .views import tsView 
from .views import DepositMoneyView, WithdrawMoneyView, TransactionReportView,LoanRequestView,LoanListView,PayLoanView
from .views import HelloView
urlpatterns = [
    path("deposit/", DepositMoneyView.as_view(), name="deposit_money"),
    path("transaction_report/", TransactionReportView.as_view(), name="transaction_report"),
    path("withdraw/", WithdrawMoneyView.as_view(), name="withdraw_money"),
    path("loan_request/", LoanRequestView.as_view(), name="loan_request"),
    path("loans/", LoanListView.as_view(), name="loan_list"),
    path("loans/<int:loan_id>/", PayLoanView.as_view(), name="pay"),

    path('hello/' , HelloView.as_view(), name='hello')
]
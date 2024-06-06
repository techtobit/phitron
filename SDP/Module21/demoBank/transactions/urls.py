from django.urls import path
from .views import tsView 

urlpatterns = [
		path('deposit/', tsView.DepositMonyView.as_view(), name='dposit_money' )
]

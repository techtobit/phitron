from django.shortcuts import render
from datetime import datetime, timedelta

# Create your views here.

def set_cookie(request):
    response = render(request, 'set_cookie.html')
    response.set_cookie('name', 'rahim')
    response.set_cookie('name', 'rahim', expires=datetime.utcnow()+timedelta(days=7))
    return response
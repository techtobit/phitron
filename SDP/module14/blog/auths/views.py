from django.shortcuts import render
from django.contrib import messages
from .forms import RegisterForm

# Create your views here.

def signup(request):
    if request.method=='POST':
        form = RegisterForm(request.POST)
        if form.is_valid():
            messages.success(request, 'Account created successfuly')
            messages.info(request, 'Welcome')
            messages.warning(request, 'Warning method check')
            form.save()
            print(form.cleaned_data)
    else:
        form = RegisterForm()
    return render(request, 'signup.html', {'from': form})

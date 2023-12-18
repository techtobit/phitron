from django.shortcuts import redirect, render
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import AuthenticationForm
from django.contrib import messages
from .forms import RegisterForm

# Create your views here.

def signup(request):
    if request.method=='POST':
        form = RegisterForm(request.POST)
        if form.is_valid():
            messages.success(request, 'Account created successfuly')
            # messages.info(request, 'Welcome')
            # messages.warning(request, 'Warning method check')
            form.save()
            print(form.cleaned_data)
    else:
        form = RegisterForm()
    return render(request, 'signup.html', {'form': form})


def user_login(request):
    if request.method == 'POST':
        form = AuthenticationForm(request=request, data=request.POST)
        if form.is_valid():
            username = request.POST["username"]
            password = request.POST["password"]
            user = authenticate(request, username=username, password=password)
            if user is not None:
                login(request, user)
                print('login in successfull')
                return redirect('profile')
    else:
        form = AuthenticationForm()
    return render(request, 'login.html', {'form':form})


def profile(request):
    return render(request, 'profile.html', {'user': request.user})

def logout_view(request):
    logout(request)
    return redirect('login')
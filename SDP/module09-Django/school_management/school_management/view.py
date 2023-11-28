from django.http import HttpResponse

def home(request):
    return HttpResponse('Welcome to Home page')

def contact(request):
    return HttpResponse('Hello This is Contact page')
from django.shortcuts import render

# Create your views here.
def navHome(request):
    return render(request, 'navHome.html')
def about(request):
    return render(request, 'about.html')
def contact(request):
    return render(request, 'contact.html')

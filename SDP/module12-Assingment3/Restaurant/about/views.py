from django.shortcuts import render

def about(request):
    if request.method == 'POST':
        name = request.POST.get('username')
        email = request.POST.get('email')
        message = request.POST.get('message')
        select = request.POST.get('select')
        return render(request, 'about.html', {'name':name, 'email': email, 'message':message, 'select':select })
    else:
        return render(request, 'about.html')

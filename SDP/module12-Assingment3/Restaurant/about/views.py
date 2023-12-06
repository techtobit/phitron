from django.shortcuts import render

def about(request):
    if request.method == 'POST':
        name = request.POST.get('username')
        email = request.POST.get('email')
        return render(request, 'about.html', {'name':name, 'email': email})
    else:
        return render(request, 'about.html')

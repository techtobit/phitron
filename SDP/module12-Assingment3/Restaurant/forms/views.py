from django.shortcuts import render

# Create your views here.
def forms(request):
    return render(request, 'forms.html')


# def submitForm(request):
#     # if request.method == 'POST':
#     #     name = request.POST.get('username')
#     #     email = request.POST.get('email')
#     #     return render(render, 'form.html', {'name' : name, 'email': email})
#     # return render(request, 'forms.html')
#     return render(request, '../forms/templates/forms.html')

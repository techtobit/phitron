from django.shortcuts import render
from . form import contactForm, StudentData, PasswordValidationForm
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

def DjangoForm(request):
    form = contactForm(request.POST, request.FILES)
    if form.is_valid():
        file = form.cleaned_data['file']
        with open('./forms/uploads' + file.name, 'wb+') as destination:
            for chunk in file.chunks():
                destination.write(chunk)
        print(form.cleaned_data)
    else:
        print(form.cleaned_data)
    return render(request, 'django_form.html', {'form': form})


def StudentForm(request):
    if request.method == 'POST':
        form = StudentData(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = StudentData()
    return render(request, 'validityChech_form.html', {'form':form})


def PasswordValidation(request):
    if request.method == 'POST':
        form = PasswordValidationForm(request.POST)
        if form.is_valid():
            print(form.cleaned_data)
    else:
        form = PasswordValidationForm()
    return render(request, 'PasswordValidation.html', {'form':form})

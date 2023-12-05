from django.shortcuts import render

# Create your views here.
def forms(request):
    return render(request, 'forms.html')

def submit_form(request):
    return render(request, '../forms/templates/forms.html')

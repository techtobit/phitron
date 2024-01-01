from django import forms
from . models import Cars
from django.forms import Textarea

class CarsFrom(forms.ModelForm):
    class Meta:
        model = Cars
        fields = ['car_name', 'car_brand', 'car_image', 'description', 'quantity', 'price']
        widgets={'description':Textarea(attrs={'cols': 3, 'rows': 3})},

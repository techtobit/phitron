from django import forms
from . models import Cars
from django.forms import Textarea

class CarsFrom(forms.ModelForm):
    class Meta:
        model = Cars
        fields = '__all__'
        widgets={"description": Textarea(attrs={"cols": 5, "rows": 20})},
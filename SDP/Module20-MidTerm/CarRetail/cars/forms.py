from django import forms
from . models import Cars, Comments
from django.forms import Textarea

class CarsFrom(forms.ModelForm):
    class Meta:
        model = Cars
        fields = ['car_name', 'car_brand', 'car_image', 'description', 'quantity', 'price']
        widgets={'description':Textarea(attrs={'cols': 3, 'rows': 3})},


class CommentFrom(forms.ModelForm):
    class Meta:
        model = Comments
        fields = ['name', 'email', 'body']
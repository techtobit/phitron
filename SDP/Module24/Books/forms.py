from django.forms import forms
from .models import Books

class BooksForm(forms.ModelForm):
		
		class Meta:
				model = Books
				fields = ("__all__")

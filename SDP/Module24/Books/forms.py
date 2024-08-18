from django import forms
from .models import Books, BookCategory

class AddBooksForm(forms.ModelForm):
		
		class Meta:
				model = Books
				fields = ("__all__")

class AddCategoryForm(forms.ModelForm):
		class Meta:
				model = BookCategory
				fields = ("__all__")

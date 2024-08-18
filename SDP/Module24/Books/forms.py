from django import forms
from .models import Books, Categories

class AddBooksForm(forms.ModelForm):
		class Meta:
				model = Books
				fields = ("__all__")
				# fields = ['title', 'author', 'category', 'price', 'image', 'description']
				widgets = {
            'description': forms.Textarea(attrs={'rows': 3, 'cols': 40}),
        }

class AddCategoryForm(forms.ModelForm):
		class Meta:
				model = Categories
				fields = ("__all__")

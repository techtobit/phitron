from django import forms
from tasklist.models import TaskList
from categories.models import Categorie

# class TaskListForm(forms.ModelForm):
#     categorie = forms.ModelMultipleChoiceField(
#     queryset=Categorie.objects.all(),
#     # widget=forms.CheckboxSelectMultiple,
#     widget=forms.SelectMultiple,
#     required=False
#     )
#     class Meta:
#         model = TaskList
#         fields = ('taskTitle', 'taskDescription', 'assign_date', 'categorie')
#         widgets = {
#             'taskDescription': forms.Textarea(attrs={'cols': 5, 'rows': 2}),
#             'assign_date': forms.DateInput(attrs={'type': 'date'}),
#         }
    



class TaskListForm(forms.ModelForm):
    categorie = forms.ModelMultipleChoiceField(
    queryset=Categorie.objects.all(),
    widget=forms.SelectMultiple,
    required=False
    )
    class Meta:
        model = TaskList
        fields = ('taskTitle', 'taskDescription', 'assign_date', 'is_complete', 'categorie')
        widgets = {
            'taskDescription': forms.Textarea(attrs={'cols': 5, 'rows': 2}),
            'assign_date': forms.DateInput(attrs={'type': 'date'}),
        }
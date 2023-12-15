from django import forms
from tasklist.models import TaskList

class TaskListForm(forms.ModelForm):
    
    class Meta:
        model = TaskList
        fields = ('taskTitle', 'taskDescription', 'assign_date')
        widgets = {
            'taskDescription': forms.Textarea(attrs={'cols': 50, 'rows': 4}),
            'assign_date': forms.DateInput(attrs={'type': 'date'}),
        }



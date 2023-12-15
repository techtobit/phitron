from django import forms
from tasklist.models import TaskList

class TaskListForm(forms.ModelForm):
    
    class Meta:
        model = TaskList
        fields = '__all__'



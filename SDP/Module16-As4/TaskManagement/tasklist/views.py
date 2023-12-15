from django.shortcuts import render, redirect
# from forms import TaskListForm
from . import forms
from . import models
# Create your views here.

def add_task(request):
    if request.method == 'POST':
        task_form = forms.TaskListForm(request.POST)
        if task_form.is_valid():
            task_form.save()
            return redirect('add_task')
    else:
        task_form = forms.TaskListForm()
    return render(request, 'add_task.html', {'form': task_form})

def show_task(request):
    tasks = models.TaskList.objects.all()
    return render(request, 'show_task.html', {'tasks': tasks})


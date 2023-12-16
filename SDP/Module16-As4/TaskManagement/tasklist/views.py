from django.shortcuts import render, redirect
from . import forms
from categories.forms import Categorie
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

def edit_task(request, id):
    task = models.TaskList.objects.get(pk=id)
    task_data = forms.TaskListFormEdit(instance=task)

    if request.method == 'POST':
        task_data = forms.TaskListFormEdit(request.POST, instance=task)
        if task_data.is_valid():
            task_data.save()
            return redirect('show_task')
    return render(request,  'add_task.html', {'form': task_data})


def delete_task(request, id):
    task = models.TaskList.objects.get(pk=id)
    print(task)
    task.delete()
    return redirect('show_task')

from django.shortcuts import render
from categories.models import Categorie
from tasklist import models



def home(request):
    return render(request, 'base.html')

def show_task(request):
    categories = Categorie.objects.all()
    tasks_by_category = {}
    for category in categories:
        tasks_by_category[category] = models.TaskList.objects.filter(categorie=category)
    # tasks = models.TaskList.objects.all()
    # return render(request, 'show_task.html', {'tasks': tasks, 'tasks_by_category':tasks_by_category})
    return render(request, 'show_task.html', {'tasks': tasks_by_category, })

def show_taskby_categorie(request):
    categories = Categorie.objects.all()
    tasks_by_category = {}
    for category in categories:
        tasks_by_category[category] = models.TaskList.objects.filter(categorie=category)
    return render(request, 'show_taskby_categorie.html', {'tasks': tasks_by_category, })

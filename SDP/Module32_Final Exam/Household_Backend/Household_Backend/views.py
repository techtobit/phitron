from django.views.generic.list import ListView 
from django.views.generic import TemplateView
from django.shortcuts import render

class Home(TemplateView):
	template_name='base.html'

# def Home(request):
# 	return render(request, 'base.hmtl')
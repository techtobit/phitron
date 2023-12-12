from django.shortcuts import render, redirect
from . import forms
from . import models
# Create your views here.

def add_post(request):
    if request.method == 'POST': # user post request koreche
        post_form = forms.PostForm(request.POST)
        if post_form.is_valid():
            post_form.save()
            return redirect('add_post')
    
    else: # user normally website e gele blank form pabe
        post_form = forms.PostForm()
    return render(request, 'add_post.html', {'form' : post_form})

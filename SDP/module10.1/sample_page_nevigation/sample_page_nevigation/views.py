from django.shortcuts import render

def home(request):
    d = {'authoer': 'Xefer', 'age': 2, 'lst':['python', 'is', 'best'], 'courses': [
        {
            'id':1,
            'name': 'Python',
            'fee': 5000
        },
        {
            'id':2,
            'name': 'Django',
            'fee': 2000
        },
        {
            'id':3,
            'name': 'C++',
            'fee': 1000
        },
        {
            'id':4,
            'name': 'DSA',
            'fee': 7000
        },
    ]}
    return render (request, 'index.html', d)
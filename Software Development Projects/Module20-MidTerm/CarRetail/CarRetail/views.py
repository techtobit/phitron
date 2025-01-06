from django.shortcuts import render, redirect
from cars.models import Cars
from brands.models import Brand
from django.db.models import Count

def home(request, brand_slug=None):
    data = Cars.objects.all()
    if brand_slug is not None:
        car_brand = Brand.objects.get(slug = brand_slug)
        data = Cars.objects.filter(car_brand = car_brand)
    # brand = Brand.objects.all()
    brand = Brand.objects.annotate(car_post_count=Count('cars')) 
    return render(request, 'home.html' , {'data': data, 'brand':brand })
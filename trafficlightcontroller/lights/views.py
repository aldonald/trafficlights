from django.http import HttpResponseRedirect
from django.urls import reverse
from django.shortcuts import render
import requests


def index(request):
    response = requests.get(
        "https://api.particle.io/v1/devices/e00fce6850c7964e4c811e41/currentLight?access_token=0d9eeda6530b74e49aeb53e0a14becfe9786fe78")
    current = response.json()['result']
    context = {
        'current': current
    }
    return render(request, 'lights/index.html', context)

def change(request):
    
    if request.method == 'POST':
        selected_choice = request.POST['choice']
        if selected_choice:
            posted = requests.post(
                "https://api.particle.io/v1/devices/e00fce6850c7964e4c811e41/trafficLight?access_token=0d9eeda6530b74e49aeb53e0a14becfe9786fe78",
                data={'arg': selected_choice})
            print(posted.__dict__)
    return HttpResponseRedirect(reverse('lights:index'))

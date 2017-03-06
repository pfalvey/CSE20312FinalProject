#!/usr/bin/env python2.7

import requests
import json

r = requests.get('http://map.nd.edu/placemarks.js')
jsonn = json.loads(r.text)
children = []
longitude = []
latitude = []
for i in jsonn:
    children.append(i['placemark']['name'])
    longitude.append(i['placemark']['midpoint'][0])
    latitude.append(i['placemark']['midpoint'][1])
for i in range(0,len(children)):
    print children[i],
    print ';' + str(longitude[i]),
    print ';' + str(latitude[i])

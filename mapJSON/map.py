#!/usr/bin/env python2.7

import unicodedata
import requests
import json

r = requests.get('http://map.nd.edu/placemarks.js')
jsonn = json.loads(r.text)
children = []
longitude = []
latitude = []
for i in jsonn: #read in json data
    children.append(i['placemark']['name'])
    longitude.append(i['placemark']['midpoint'][0])
    latitude.append(i['placemark']['midpoint'][1])
#open new file
file = open("locations.txt","w")
#write data to file
for i in range(0,len(children)):
    #get rid of unicode characters in json data
    children[i]=unicodedata.normalize('NFKD', children[i]).encode('ascii','ignore')
    file.write(children[i]+';'+str(longitude[i])+";"+str(latitude[i])+'\n')

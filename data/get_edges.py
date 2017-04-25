#!/usr/bin/env python2.7

#generates a text file of adjacent nodes and distances for the graph class

import json
import requests

cutoff_distance = 1848           #every building within a 1848 foot radius will be an edge
lat_to_feet = 364393.7354401166  #conversion from one degree of latitude to feet at Notre Dame
long_to_feet = 273092.431579933    #conversion from one degree of longitude to feet at Notre Dame

f = open('locations.txt', 'r')
for i in f:
    print i

#!/usr/bin/env python2.7

#generates a text file of adjacent nodes and distances for the graph class

import json
import requests
import math

cutoff_distance = 560           #every building within a 560 foot radius will be an edge. 
#There will be edge cases (no pun intended) for buildings such as Carroll Hall, and those will be manually entered in.
lat_to_feet = 364393.7354401166  #conversion from one degree of latitude to feet at Notre Dame
long_to_feet = 273092.431579933    #conversion from one degree of longitude to feet at Notre Dame

#open existing file
f1 = open('locations.txt', 'r')
#open new file
file = open("edges.txt", "w")

#nest for loop to check all the buildings for other buildings that are within the cutoff distance
for i in f1:
    i = i.strip() #formatting the line
    i = i.split(';')
    f2 = open('locations.txt', 'r') #open another copy of locations.txt
    edges = [] #will store the edges for each building
    distance = [] #will store the distances of the edges for each building
    for j in f2:
        j = j.strip() #formatting the line
        j = j.split(';')
        x1 = float(i[2]) * lat_to_feet #converting coordinates to feet
        x2 = float(j[2]) * lat_to_feet
        y1 = float(i[3]) * lat_to_feet
        y2 = float(j[3]) * lat_to_feet
        #find distance and compare to cutoff distance
        dist = math.hypot(float(x2) - float(x1), float(y2) - float(y1))
        if dist < cutoff_distance and dist > 0:
            name = j[0]
            edges.append(name)
            distance.append(dist)
        #write to the file edges.txt
    file.write(i[0] + "\n")
    file.write(str(len(edges)) + "\n")
    for temp1, temp2 in zip(edges, distance):
        file.write(temp1 + " " + str(temp2) + "\n")
    if i[0] != "ZAHM": #add newline except for the end
        file.write("\n")

        

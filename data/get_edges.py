#!/usr/bin/env python2.7

#generates a text file of adjacent nodes and distances for the graph class
#format of file for each building will be...
#KEY   (name of building)
#NUMBER_OF_EDGES
#EDGE DISTANCE_TO_EDGE

import json
import requests
import math
import os

cutoff_distance = 560           #every building within a 560 foot radius will be an edge. 
#There will be edge cases (no pun intended) for buildings with minimum edges of over 560 feet which will be handled by keeping track of the two shortest edges
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
    #keep track of two shortest edges for "edge cases"
    shortest_dist_1 = 5280
    shortest_dist_2 = 5281
    shortest_name_1 = ""
    shortest_name_2 = ""
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
        #update shortest distance edges
        if dist < shortest_dist_1 and dist > 0:
            shortest_name_2 = shortest_name_1
            shortest_dist_2 = shortest_dist_1
            shortest_name_1 = j[0]
            shortest_dist_1 = dist
        elif dist < shortest_dist_2 and dist > 0:
            shortest_name_2 = j[0]
            shortest_dist_2 = dist
        
    #make sure each building has at least two edges
    if len(edges) == 0:
        edges.append(shortest_name_1)
        distance.append(shortest_dist_1)
        edges.append(shortest_name_2)
        distance.append(shortest_dist_2)
    elif len(edges) == 1:
        edges.append(shortest_name_2)
        distance.append(shortest_dist_2)

    #write to file
    file.write(i[0] + "\n")
    file.write(i[1] + "\n")
    file.write(i[2] + "\n")
    file.write(i[3] + "\n")
    file.write(str(len(edges)) + "\n")
    for temp1, temp2 in zip(edges, distance):
        file.write(temp1 + " " + str(temp2) + "\n")
    if i[0] != "ZAHM": #add newline except for the end
        file.write("\n")

        

#!/usr/bin/env python2.7

#generates a text file of adjacent nodes and distances for the graph class
#format of file for each building will be...
#KEY   (name of building)
#NUMBER_OF_EDGES
#EDGE DISTANCE_TO_EDGE

import json
import math
import os
import urllib

cutoff_distance = 560           #every building within a 560 foot radius will be an edge. 
#There will be edge cases (no pun intended) for buildings with minimum edges of over 560 feet which will be handled by keeping track of the two shortest edges
lat_to_feet = 364393.7354401166  #conversion from one degree of latitude to feet at Notre Dame
long_to_feet = 273092.431579933    #conversion from one degree of longitude to feet at Notre Dame


#google maps api keys are stored on the Notre Dame network and can only be accessed on the Notre Dame network. This is for safety/privacy
placeKeyFile = open('/afs/nd.edu/user36/pfalvey/Public/cse20312project/key3', 'r') #can use /key1 or /key3 if either surpass their daily request quota
mapKeyFile = open('/afs/nd.edu/user36/pfalvey/Public/cse20312project/key4', 'r') #can use /key2 or /key4 if either surpass their daily request quota
placeKey = placeKeyFile.readline()
mapKey = mapKeyFile.readline()



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
    #get PlaceID from google api
    placeURL = "https://maps.googleapis.com/maps/api/geocode/json?latlng={},{}&key={}".format(i[2],i[3],placeKey)
    placeURL.strip()
    r1 = urllib.urlopen(placeURL)
    jsonn = json.loads(r1.read())
    print jsonn
    placeID1= jsonn['results'][0]['place_id']
    for j in f2:
        j = j.strip() #formatting the line
        j = j.split(';')
        x1 = float(i[2]) * lat_to_feet #converting coordinates to feet
        x2 = float(j[2]) * lat_to_feet
        y1 = float(i[3]) * long_to_feet
        y2 = float(j[3]) * long_to_feet


        #find distance and compare to cutoff distance
        dist = math.hypot(float(x2) - float(x1), float(y2) - float(y1))
        if dist < cutoff_distance and dist > 0:
            name = j[0]
            edges.append(name)
            #get building place ID andactual distance from google maps api
            placeURL2 = "https://maps.googleapis.com/maps/api/geocode/json?latlng={},{}&key={}".format(j[2],j[3],placeKey)
            placeURL2.strip()
            r2 = urllib.urlopen(placeURL2)
            jsonn2 = json.loads(r2.read())
            placeID2 = jsonn2['results'][0]['place_id']
            mapURL="https://maps.googleapis.com/maps/api/distancematrix/json?origins=place_id:{}&destinations=place_id:{}&mode=walking&units=imperial&key={}".format(placeID1, placeID2, mapKey)
            mapURL.strip()
            r3 = urllib.urlopen(mapURL)
            jsonn3 = json.loads(r3.read())
            newdist = jsonn3['rows'][0]['elements'][0]['distance']['value']
            newdist = float(newdist)
            newdist = newdist * 3
            if newdist > 0:
                distance.append(newdist)
            else:
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

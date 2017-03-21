#!/usr/bin/env python2.7

mapdict = {}
with open('./locations.txt','r') as file:
    for line in file:
        linelist = line.rstrip().split(";")
        mapdict[linelist[0]] = [linelist[1],linelist[2],linelist[3]]

with open('./map.json','w') as file:
    file.write(str(mapdict))

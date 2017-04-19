My map.py script downloads the JSON data from Notre Dame's campus map 
website. I then create a text file with the placemark names (building
names), longitudes, and latitudes of those placemarks and separate them by
the ";" character. The text file is called locations.txt.

The storeData.cpp program reads in the data from the locations.txt file
and stores this data in a STD map. The program then prints the contents
of the map to ensure everything was copied correctly. The executable
for this is called getData.

In order to run this program, execute the runCode.sh script.
Type ./runCode.sh
This will compile the code, run the map.py program to generate the file
of locations, execute the storeData command and display the results, and
finally count the line numbers of the results of the storeData executable
and the locations.txt file to ensure that they have the same locations.
The program might take a couple of seconds to run.



/* Patrick Falvey storeData.cpp 
 * a program that reads a text file of map information and stores it in
 * a map. 3/12/17 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

struct place{ //represents a placemark on the campus map
    float longitude;
    float latitude;
};

int main(){
    
    map<string, place> campus; //create new map
    ifstream ifs; //to read in file
    string filename="locations.txt";
    string placename, Lon, Lat;
    float lon, lat;
    ifs.open(filename); //open file
    char c = ifs.peek();
    int count = 0; //helper variable with duplicate keys
    while(c != EOF) {
        getline(ifs, placename, ';');  //parse text file with ; as delimiter
        getline(ifs, Lon, ';');
        getline(ifs, Lat, '\n');
        lon = stof(Lon);
        lat = stof(Lat);
        
        place temp = {lon, lat}; //create new place struct
        
        //check if key does not exists already in the map
        if(campus.find(placename) == campus.end()) { 
            campus.insert(pair<string,place>(placename,temp));
        } else { //if key already exists, add arbitrary number to placename
            placename = placename + " " + to_string(count);
            count++; 
            campus.insert(pair<string,place>(placename,temp));
        
            c = ifs.peek();
        }
    }
    campus.erase(campus.begin());
    campus.erase(campus.begin());
    //print contents of map    
    for (auto it = campus.begin(); it!=campus.end(); ++it)
        cout<<it->first << " => " << it->second.longitude << " " <<it->second.latitude<<'\n';

}
    


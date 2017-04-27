/*
Main + i/o for map application
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "Graph.h"

void parseFlags();
void usage(int);
void loadGraph( char *, Graph * );


int main(int argc, char ** argv){
  Graph g;
  loadGraph("data/locations.txt", &g);
  g.addedges();
  if( argc <2 ){
    usage(1);
  }


return 0;
}



/*
Parse command-line arguments from a stream

*/
void parseFlags(){

}


/*
Display usage and exit with the given status
*/
void usage( int status ){
  std::cout <<"USAGE:\n\tmap path_length start_point [middle_points] end_point\n\n";
  std::cout <<"path_length:\tdistance you wish to traverse (in feet)\n";
  std::cout <<"start_point:\tpoint where path starts\n";
  std::cout <<"end_point:\tpoint where path ends\n";
  std::cout <<"(OPTIONAL)middle_points:\tAny additional points to traverse through\n";
  exit(status);
}

/* 
load graph data from locations 
*/
void loadGraph( char * fname, Graph * g ){
   std::ifstream f(fname);
   std::string ln;
   
   while( std::getline( f, ln ) ){
     std::string key,name;
     double x, y;
     int i = 0, old_i = i;
     //Count to first ';'
     while( ln.substr(++i,1) != ";" ){}
     key = ln.substr(old_i,i-old_i);
     old_i = ++i;
 
     //Count to second ';'
     while( ln.substr(++i,1) != ";" ){}
     name = ln.substr(old_i,i-old_i);
     old_i = ++i;
     
     //Count to third ';'
     while( ln.substr(++i,1) != ";" ){}
     x = atof( ln.substr(old_i,i-old_i).c_str() );
     old_i = ++i;
 
     //Count to end
     y = atof( ln.substr(old_i, (ln.size()-old_i ) ).c_str()  );
     g->insert( key, name, x, y );
   }
 
 }




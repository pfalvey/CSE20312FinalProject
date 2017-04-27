/*
Main + i/o for map application
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

#include "Graph.h"

void parseFlags();
void usage(int);
void loadGraph( const char *, Graph * );


int main(int argc, char ** argv){
  if( argc <2 ){
    usage(1);
  }

  //int pathlength = argv[1];
  std::string startnodekey = argv[2];
  std::string endnodekey = argv[3];

  Graph g;
  loadGraph("data/locations.txt", &g);
  g.addedges();

  Node * startnode = g.get(startnodekey);
  Node * endnode = g.get(endnodekey);
  if (!startnode || !endnode) usage(1);

  g.astar(startnode, endnode);


return EXIT_SUCCESS;
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
  std::cout <<"middle_points:\t(OPTIONAL) Any additional points to traverse through\n";
  exit(status);
}

/*
load graph data from locations
*/
void loadGraph( const char * fname, Graph * g ){
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

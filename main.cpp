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

  dist pathlength = atof(argv[1]);
  std::string startnodekey = argv[2];
  std::string endnodekey = argv[3];

  Graph g;
  loadGraph("data/edges.txt", &g);

  Node * startnode = g.get(startnodekey);
  Node * endnode = g.get(endnodekey);
  if (!startnode || !endnode) usage(1);

  g.estar(startnode, endnode, pathlength);


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

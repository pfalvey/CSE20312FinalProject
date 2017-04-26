/*
Main + i/o for map application
*/

#include <iostream>
#include <stdlib.h>

#include "Graph.h"

void parseFlags();
void usage(int);


int main(int argc, char ** argv){
  Graph g;
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






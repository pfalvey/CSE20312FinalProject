/*
Main + i/o for map application
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>


#include "Graph.h"

void usage(int);
void list(int);
void loadGraph( const char *, Graph * );


int main(int argc, char ** argv){
  //parse command line arguments
  if( argc <2 || argc >4){
    usage(1);
  }
  std::string help;
  std::string startnodekey;
  std::string endnodekey;
  dist pathlength;
  if (argc == 2){
      help = argv[1];
  }
  if (argc == 3){
      usage(1);
  }
  if (argc == 4){
    pathlength = atof(argv[1]);
    startnodekey = argv[2];
    endnodekey = argv[3];
  }

  if (argc == 2 && (help.compare("--help") == 0 || help.compare("-h") == 0))
      usage(0);
  else if (argc == 2 && (help.compare("--list") == 0 || help.compare("-l") == 0))
      list(0);
  else if (argc == 2)
      usage(1);

  //build graph
  Graph g;
  loadGraph("data/edges.txt", &g);

  Node * startnode = g.get(startnodekey);
  Node * endnode = g.get(endnodekey);
  if (!startnode || !endnode) usage(1);

  g.tvsida_star(startnode, endnode, pathlength);


return EXIT_SUCCESS;
}



/*
Display usage and exit with the given status
*/
void usage( int status ){
  std::cout <<"USAGE:\n\tmap [-l | --list] [-h | --help]  <path_length> <start_point> <end_point>\n\n";
  std::cout <<"path_length:\tdistance you wish to traverse (in feet)\n";
  std::cout <<"start_point:\tpoint where path starts\n";
  std::cout <<"end_point:\tpoint where path ends\n";
  exit(status);
}

/*
Display list and exit with the given status
*/
void list( int status ){
  std::ifstream ifs;
  ifs.open("data/locations.txt");
  std::string input;
  while(std::getline(ifs, input)){
    std::stringstream output;
    output<<input;
    getline(output, input, ';');
    std::cout<<input<<std::endl;
  }

  exit(status);
}

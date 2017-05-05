/*
 * main.cpp: main() function, which instantiates Graph object, parses command
 * line arguments, and calls Graph::tvsida_star().
 */

#include <iostream>
#include <string>

#include "Graph.h"

void usage(int);
void loadGraph( const char *, Graph * );


int main(int argc, char ** argv){
  //build graph
  Graph g;
  loadGraph("data/edges.txt", &g);

  if( argc <2 || argc >4){
    usage(EXIT_FAILURE);
  }

  std::string help;
  std::string startnodekey;
  std::string endnodekey;
  dist pathlength = 0;
  Node * startnode = nullptr;
  Node * endnode = nullptr;

  /* Parse command line arguments */
  int argind = 1;
  while (argind < argc && strlen(argv[argind]) > 1 && argv[argind][0] == '-') {
    char *arg = argv[argind++];
    if (strcmp(arg,"-h") == 0 || strcmp(arg,"--help") == 0) {
      usage(EXIT_SUCCESS);
    } else if (strcmp(arg, "-l") == 0 || strcmp(arg, "--list") == 0) {
      g.nodedump();
      return EXIT_SUCCESS;
    } else usage(EXIT_FAILURE);
  }

  if (argc > argind) {
    startnodekey = argv[argind++];
    startnode = g.get(startnodekey);
    if (!startnode) {
      std::cout << "ERROR: " << startnodekey << " does not exist" << std::endl;
      usage(EXIT_FAILURE);
    }
  }

  if (argc > argind) {
    endnodekey = argv[argind++];
    endnode = g.get(endnodekey);
    if (!endnode) {
      std::cout << "ERROR: " << endnodekey << " does not exist" << std::endl;
      usage(EXIT_FAILURE);
    }
  }

  if (argc > argind) {
    pathlength = atof(argv[argind]);
  }

  /* Run graph traversal */
  g.tvsida_star(startnode, endnode, pathlength);


return EXIT_SUCCESS;
}



/*
 * Display usage and exit with the given status
 */
void usage( int status ){
  std::cout <<"USAGE:\n\tmap [-l | --list] [-h | --help]  <start_point> <end_point> <path_length> \n\n";
  std::cout <<"start_point:\tpoint where path starts\n";
  std::cout <<"end_point:\tpoint where path ends\n";
  std::cout <<"path_length:\tdistance you wish to traverse (in feet)\n";
  exit(status);
}

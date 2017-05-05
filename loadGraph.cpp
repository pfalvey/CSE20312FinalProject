/*
 * loadGraph.cpp: defines loadGraph function to read in graph data from file
 * and add it to a graph object.
 */

#include <fstream>
#include <sstream>
#include <string>

#include "Graph.h"

/*
load graph data from locations
*/
void loadGraph( const char * fname, Graph * g ){
  std::ifstream f(fname);
  std::string ln;

  while( std::getline(f, ln) ){
    if (ln.compare("") == 0){
      std::getline( f, ln );
    }
    //Acquire keys
    std::string key = ln;
    //Get name
    std::getline( f, ln );
    std::string name = ln;
    //X coordinate
    std::getline( f, ln );
    dist y = atof( ln.c_str() );
    //Y coordinate
    std::getline( f, ln );
    dist x = atof( ln.c_str() );

    //add this new node
    g->insert(key,name,x,y);

    // add edges
    int i;
    std::getline(f,ln);
    i = atoi(ln.c_str());

    for(int a =0; a < i; ++a){
      std::getline(f, ln);
      std::stringstream ss(ln);
      std::string edge_key;
      std::string edge_Dist;
      ss>>edge_key;
      ss>>edge_Dist;

      int edge_dist = atof(edge_Dist.c_str());

      g->insert_edge(key,edge_key,edge_dist);
    }
  }

}

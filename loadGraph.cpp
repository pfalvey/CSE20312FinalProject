#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>

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
    dist x = atof( ln.c_str() );    
    //Y coordinate
    std::getline( f, ln );
    dist y = atof( ln.c_str() );    

    //add this new node
    g->insert(key,name,x,y);

    //find extra nodes and add them
    int i;
    f >> i;
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







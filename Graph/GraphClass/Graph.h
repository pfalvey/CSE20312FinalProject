#ifndef GRAPH_H
#define GRAPH_H


#include <set>
#include <pair>

#include <vector>


struct Node{
  char * name;
  std::pair<double,double> coords;
  std::vector<  std::pair<Node*, double > > * adjacent;
};


class Graph{
public:
  Graph();
  ~Graph();

  insert();
  insert( std::string, std::string, double, double );

  Node * get( std::string );

  

private:
  std::<set> nodes;
};
#endif

#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <string>
#include <vector>

typedef int dist;

struct Node{
  std::string name;
  std::pair<dist,dist> coords;
  std::vector<  std::pair<Node*, dist > > * adjacent;
};


class Graph{
public:
  Graph();
  ~Graph();

  void insert();
  void insert( std::string, std::string, dist, dist );

  Node * get( std::string );

  std::map<std::string, Node*> nodes;
};
#endif

#ifndef GRAPH_H
#define GRAPH_H


#include <map>
#include <string>
#include <vector>

typedef double dist;

#define LAT_TO_FEET 364393.7354401166
#define LONG_TO_FEET 273092.431579933 

struct Node{
  std::string name;
  std::pair<dist,dist> coords;
  std::vector<  std::pair<Node*, dist > > * adjacent;
};


class Graph{
public:
  Graph();
  ~Graph();

  void buildgraph( std::string filename );
  void insert();
  void insert( std::string, std::string, dist, dist );

  void insert_edge(std::string, std::string,dist);

  void addedges();

  dist astar( Node * start, Node * end );
  dist estar( Node * start, Node * end, dist distance );

  Node * get( std::string );

private:
  std::map<std::string, Node*> nodes;
};
#endif

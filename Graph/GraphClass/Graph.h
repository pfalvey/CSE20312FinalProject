#ifndef GRAPH_H
#define GRAPH_H

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property,boost::property< boost::edge_weight_t, int >  > UndirectedGraph;

class Graph{
public:
  Graph();
  ~Graph();
  void insert_node( const int * );
  void insert_edge(const int, const int, const int);

  int lookup( int );

  void print();
private:
  UndirectedGraph core;
  int size = 0;
};
#endif

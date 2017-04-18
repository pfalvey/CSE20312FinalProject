#include "Graph.h"
#include <iostream>

Graph::Graph(){}

Graph::~Graph(){}

//insert standard info into a graph
void Graph::insert(std::string key, std::string name, dist xcor, dist ycor){
  Node * n = new Node ;
  n->name = name;
  n->coords = std::pair<dist,dist>(xcor,ycor);
  n->adjacent = new std::vector< std::pair<Node*,dist> >;

  nodes[key] = n;
}

//generic insert
void Graph::insert(){
  insert("","",0,0);
}

Node * Graph::get( std::string key ){
  if ( nodes[key] == NULL ){
    return NULL;
  }
  return nodes[key];
}


//Overloaded operator for set insertion
bool operator<(const Node n1, const Node n2){
  return n1.name.compare(n2.name);
}

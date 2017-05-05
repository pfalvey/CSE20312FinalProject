#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

Graph::Graph(){}

Graph::~Graph(){
  for (auto it = nodes.begin(); it != nodes.end(); it++) {
    delete it->second->adjacent;
    delete it->second;
  }
}

//insert standard info into a graph
void Graph::insert(std::string key, std::string name, dist xcor, dist ycor){
  Node * n = new Node ;
  n->name = name;
  n->coords = std::pair<dist,dist>(xcor,ycor);
  n->adjacent = new std::vector< std::pair<std::string,dist> >;

  nodes[key] = n;
}

//generic insert
void Graph::insert(){
  insert("","",0,0);
}

void Graph::insert_edge(std::string a, std::string b, dist d ){
  std::pair<std::string, dist> p;
  p.first = b;
  p.second = d;
  if ( nodes.find(a) != nodes.end() ){
    nodes[a]->adjacent->push_back( p );
  }

  p.first = a;
  if ( nodes.find(b) != nodes.end() ){
    nodes[b]->adjacent->push_back( p );
  }
}



Node * Graph::get( std::string key ){
  if ( nodes.count(key) < 1 ){
    return NULL;
  }
  return nodes[key];
}

void Graph::nodedump() {
  for (auto it = nodes.begin(); it != nodes.end(); it++) {
    std::cout << it->first << std::endl;
  }
}


//Overloaded operator for set insertion
bool operator<(const Node n1, const Node n2){
  return n1.name.compare(n2.name);
}

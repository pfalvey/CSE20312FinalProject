#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void Graph::addegdes(){
    std::string filename = "data/edges.txt";
    std::ifstream ifs(filenam );
    std::string line;
    while( std::getline( ifs, line ) ){
        if (line.compare("") == 0)
            std::getline( ifs, line );
        std::string key = line;
        std::getline( ifs, line );
        int num_edges = atof(line);
        for (int i = 0; i < num_edges; i++){
            std::getline( ifs, line );
            std::stringstream ss(line);
            std::string edge_key;
            std::string edge_Dist;
            ss>>edge_key;
            ss>>edge_Dist;
            int edge_dist = atof(edge_Dist);
            //todo
            //access current graph node and add this info to its edges vectors

}

Node * Graph::get( std::string key ){
  if ( nodes.count(key) < 1 ){
    return NULL;
  }
  return nodes[key];
}


//Overloaded operator for set insertion
bool operator<(const Node n1, const Node n2){
  return n1.name.compare(n2.name);
}

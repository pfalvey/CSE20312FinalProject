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
  nodes[a]->adjacent->push_back( p );

  p.first = a;
  nodes[b]->adjacent->push_back( p );
}

void Graph::addedges(){
    std::string filename = "data/edges.txt";
    std::ifstream ifs(filename );
    std::string line;
    while( std::getline( ifs, line ) ){
        if (line.compare("") == 0){
            std::getline( ifs, line );
        }
        std::string key = line;
        std::getline( ifs, line );
        //std::cout << line << "\n";
        int num_edges = atof(line.c_str());
        for (int i = 0; i < num_edges; i++){
            std::getline( ifs, line );
            std::stringstream ss(line);
            std::string edge_key;
            std::string edge_Dist;
            ss>>edge_key;
            ss>>edge_Dist;
            //std::cout << edge_Dist << "\n";
            int edge_dist = atof(edge_Dist.c_str());
            //todo
            //access current graph node and add this info to its edges vectors
            insert_edge( key, edge_key, edge_dist );
        }
    }
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

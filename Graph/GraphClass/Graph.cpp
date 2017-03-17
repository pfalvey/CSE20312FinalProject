#include "Graph.h"
#include <iostream>

Graph::Graph(){}

Graph::~Graph(){}

void Graph::insert_edge(const int start, const int end, const int length){
  boost::add_edge(start,end,length,core);
}



void Graph::print(){
  typedef boost::graph_traits<UndirectedGraph>::edge_iterator gi;
	std::pair<gi, gi> ei = boost::edges(core);

  std::cout <<"0:(start,end  weight)";
  int i =0;
  for(gi edge_iter=ei.first; edge_iter!=ei.second; ++ edge_iter){
    std::cout<< ++i <<":( "<< boost::source(*edge_iter,core) <<","<< boost::target(*edge_iter,core) << "  "<< boost::get( boost::edge_weight_t(), core, *edge_iter ) << " )\n";
  }
  
}

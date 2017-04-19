#include <iostream>
#include <vector>
#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"


int main(){

	//Define edge based on endpoint nodes
	typedef std::pair<int,int> Edge;
	std::vector<Edge> edges;

	edges.push_back( Edge(0,1) );
	edges.push_back( Edge(0,2) );
	edges.push_back( Edge(0,3) );

	typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, boost::no_property,boost::property< boost::edge_weight_t, int >  > UndirectedGraph;

	//UndirectedGraph g(edges.begin(), edges.end(), 1);
	UndirectedGraph g;
	//Count edges of the graph
	std::cout << "EDGES: "<< boost::num_edges(g) << "\n";

	//Add another edge to the graph
	boost::add_edge(0,4,40,g);

	//Iterating through graph edges
	typedef boost::graph_traits<UndirectedGraph>::edge_iterator iterator;
	std::pair<iterator,iterator> ei = boost::edges(g);
	
	for(iterator edge_iter=ei.first; edge_iter!=ei.second; ++edge_iter){
		std::cout<<"("<< boost::source(*edge_iter, g) << boost::target(*edge_iter, g) << " "<< boost::get(boost::edge_weight_t(), g, *edge_iter) << ")\n";
	}

return 0;
}

#include "Graph.h"
#include <set>
#include <cmath>

// Only needed for debugging
#include <list>
#include <iostream>

dist heuristic(Node * start, Node * end);

dist Graph::astar(Node *start, Node *end) {
	std::map<Node *, dist> openset = {}; // value == path_dist+heuristic
	openset[start] = heuristic(start,end);
	auto min_openset = openset.begin(); // map entry with lowest value

	std::map<Node *, dist> closedset = {};
	std::map<Node *, Node *> camefrom = {};
	std::map<Node *, dist> path_dist = {};
	path_dist[start] = 0;

	Node * current = nullptr;

	while(openset.size() > 0) {
		current = min_openset->first;
		dist current_dist = min_openset->second;
		if (current == end) break;

		openset.erase(current);
		closedset[current] = current_dist;

		for (auto neighbor = current->adjacent->begin(); neighbor != current->adjacent->end(); neighbor++) {
			if (closedset.count(neighbor->first) > 0) continue;

			dist new_path_dist = path_dist[current] + neighbor->second;
			if (openset.count(neighbor->first) == 0) //neighbor is not in openset
				openset[neighbor->first] = 0; //add neighbor to openset
			else if (new_path_dist >= path_dist[neighbor->first]) continue; //longer, redundant path

			path_dist[neighbor->first] = new_path_dist;
			openset[neighbor->first] = new_path_dist + heuristic(neighbor->first, end);
			camefrom[neighbor->first] = current;

			//update min_openset
			if (openset[neighbor->first] < min_openset->second)
				min_openset = openset.find(neighbor->first);
		}
	}

	//-----Compile and print path (debugging)-----
	std::list<std::string> path;
	Node * n = current;
	while (n != start) {
		path.push_front(n->name);
		n = camefrom[n];
	}
	path.push_front(n->name);

	for (auto it = path.begin(); it != path.end(); it++) {
		std::cout << *it << std::endl;
	}
	std::cout << "Distance: " << path_dist[current] << " feet" << std::endl;
	//-----End Debugging-----

	return path_dist[current];
}

// Returns Cartesian distance between nodes using lat/long coordinates
dist heuristic(Node * start, Node * end) {
	dist heuristic = 0;
	dist xdist =  std::abs(start->coords.first - end->coords.first);
	dist ydist = std::abs(start->coords.second - end->coords.second);
	xdist *= LONG_TO_FEET;
	ydist *= LAT_TO_FEET;
	heuristic = std::sqrt(std::pow(xdist,2) + std::pow(ydist,2));

	return heuristic;
}

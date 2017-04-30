#include "Graph.h"
#include <set>
#include <cmath>

// Only needed for debugging
#include <list>
#include <iostream>
#include <unistd.h>

extern dist heuristic(Node * start, Node * end);

dist Graph::estar(Node *start, Node *end, dist target) {
	std::map<Node *, dist> openset = {}; // value == path_dist+heuristic
	openset[start] = heuristic(start,end);
	Node * min_openset = openset.begin()->first; // map entry with lowest value

	std::map<Node *, dist> closedset = {}; // nodes already explored
	std::map<Node *, Node *> camefrom = {}; // stores the last node in the path for each node explored
	std::map<Node *, dist> path_dist = {}; // stores distance from start node to each explored node
	path_dist[start] = 0;

	Node * current = nullptr;

	while(openset.size() > 0) {
		current = min_openset;
		dist current_dist = openset[min_openset];
		if (current == end && path_dist[current] > target) break;

		openset.erase(current);
		if (current != end) closedset[current] = current_dist;

		for (auto neighbor = current->adjacent->begin(); neighbor != current->adjacent->end(); neighbor++) {
			if (closedset.count(nodes[neighbor->first]) > 0) continue; //already in closed set

			dist new_path_dist = path_dist[current] + neighbor->second;
			if (openset.count(nodes[neighbor->first]) == 0) //neighbor is not in openset
				openset[nodes[neighbor->first]] = 0; //add neighbor to openset
			else if (new_path_dist >= path_dist[nodes[neighbor->first]]) continue; //longer, redundant path

			path_dist[nodes[neighbor->first]] = new_path_dist;
			openset[nodes[neighbor->first]] = new_path_dist + heuristic(nodes[neighbor->first], end);
			camefrom[nodes[neighbor->first]] = current;
		}

		// Update min_openset
		min_openset = openset.begin()->first;
		for (auto it = openset.begin(); it != openset.end(); it++) {
			if (it->second < openset[min_openset]) min_openset = it->first;
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

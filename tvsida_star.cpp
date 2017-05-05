/* 
 * Implementation of Target-Value Search, Iterative Deepening A*
 * Algorithm based on Lopez, Stern and Felner:
 * http://www.ijcai.org/Proceedings/13/Papers/096.pdf
 * Finds path between two nodes closest to target length, and prints result
 * Uses tvsida_recurisve helper function, as well as heuristic() defined in
 * astar.cpp
 */

#include "Graph.h"
#include <cmath>
#include <list>
#include <iostream>

typedef std::pair<dist, std::list<Node *> > path;

extern dist heuristic(Node* current, Node * end);
path tvsida_recursive(Graph &g, path workingpath, Node * current, Node * end, dist nodecost, dist target);

// Implements TVS-IDA* algorithm
dist Graph::tvsida_star(Node *start, Node *end, dist target) {
	dist min_distance = astar(start, end, false);
	if (min_distance >= target) {
		astar(start, end, true); //print result
		return min_distance;
	}

	path best;
	best.first = 0;
	dist bound = target;
	while (std::abs(bound-target) < std::abs(best.first-target)) {
		path workingpath;
		path current = tvsida_recursive(*this, workingpath, start, end, 0, bound);
		if (current.first < 0) {
			std::cout << "Error: Path not found" << std::endl;
			return EXIT_FAILURE;
		}
		if (best.first <= 0) best = current;
		else if (std::abs(current.first-target) < std::abs(best.first-target)) best = current;
		if (best.first - target == 0) break;
		bound += std::abs(current.first - target);
	}

	// Print path
	for (auto it = best.second.begin(); it != best.second.end(); it++) {
		std::cout << (*it)->name << std::endl;
	}
	std::cout << "Distance: " << best.first << " feet" << std:: endl;

	return best.first;
}

// Recursive helper function for Graph::tvsida_star
path tvsida_recursive(Graph &g, path workingpath, Node * current, Node * end, dist nodecost, dist bound) {
	for (auto it = workingpath.second.begin(); it != workingpath.second.end(); it++) {
		if (*it == current) return workingpath; //node already visited
	}

	if (nodecost + heuristic(current, end) > bound) {
		// Node is beyond search bound
		workingpath.first = -1;
		return workingpath;
	}

	workingpath.second.push_back(current);

	if (current == end) { //goal reached
		return workingpath;
	}

	for (auto it = current->adjacent->begin(); it != current->adjacent->end(); it++) {
		Node * neighbor = g.get(it->first);

		bool visited = false;
		for (auto it = workingpath.second.begin(); it != workingpath.second.end(); it++) {
			if (*it == neighbor) visited = true; //check if neighbor is already in path
		}
		if (visited) continue;

		path possible = tvsida_recursive(g, workingpath, neighbor, end, nodecost+it->second, bound);
		if (possible.first < 0) continue; //Error on path, or node not added
		possible.first += it->second;
		if (*(--possible.second.end()) == end) {
			if (workingpath.first == nodecost) workingpath = possible; //first valid path
			else if (std::abs(nodecost + possible.first - bound) < std::abs(nodecost + workingpath.first - bound)) workingpath = possible;
		}

	}
	return workingpath;
}

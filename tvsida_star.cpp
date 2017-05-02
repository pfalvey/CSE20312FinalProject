/* Implementation of Target-Value Search, Iterative Deepening A*
 * Algorithm based on Lopez, Stern and Felner:
 * http://www.ijcai.org/Proceedings/13/Papers/096.pdf
 */

#include "Graph.h"
#include <cmath>
#include <list>
#include <iostream>

typedef std::pair<dist, std::list<Node *> > path;

extern dist heuristic(Node* current, Node * end);
dist tvs_heuristic(std::map<Node*, dist> &, Node * start, dist target);
path tvsida_recursive(Graph &g, Node * current, Node * end, dist nodecost, dist target);

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
		path current = tvsida_recursive(*this, start, end, 0, bound);
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

path tvsida_recursive(Graph &g, Node * current, Node * end, dist nodecost, dist bound) {
	path best;
	best.first = 0;

	if (nodecost + heuristic(current, end) > bound) {
		// Node is beyond search bound
		best.first = -1; //negative distance -> error code
		return best;
	}

	if (current == end) { //goal reached
		best.second.push_front(current);
		return best;
	}

	for (auto it = current->adjacent->begin(); it != current->adjacent->end(); it++) {
		Node * neighbor = g.get(it->first);
		path possible = tvsida_recursive(g, neighbor, end, nodecost+it->second, bound);
		possible.second.push_front(current);
		if (possible.first < 0) continue; //Error on path
		possible.first += it->second;
		if (*(--possible.second.end()) == end) {
			if (best.first == 0) best = possible; //first valid path
			else if (std::abs(nodecost + possible.first - bound) < std::abs(nodecost + best.first - bound)) best = possible;
		}

	}
	return best;
}

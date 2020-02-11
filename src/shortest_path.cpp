/*
 * shortest_path.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: andrea.yuste
 */

#include <numeric>

#include "../include/shortest_path.h"
#include "../include/priority_queue.h"

// PROPOSED METHODS

ShortestPath::ShortestPath(const Graph &G) :
		G(G) {
}

// List of vertices in G(V,E) ???
std::vector<int> ShortestPath::vertices() {

	vector<int> lista(G.V());
	iota(lista.begin(), lista.end(), 0);

	return lista;
}

std::vector<int> ShortestPath::path(const int &u, const int &w) {

	PriorityQueue path_queue(G);
	path_queue.insert(u, 0);

	int center = u;
	std::vector<int> adjacents = G.neighbors(center);

	return adjacents;
}

int ShortestPath::path_size(const int &u, const int &w) {

	PriorityQueue open_queue(G);
	PriorityQueue closed_queue(G);

	closed_queue.insert(u, 0);

	int center = u;

	while (!closed_queue.contains(w)) {
		std::vector<int> adjacents = G.neighbors(center);
		for (int &it : adjacents) {
			if (!closed_queue.contains(it)) {
				int priority = G.get_edge_value(center, it)
						+ closed_queue.get_priority(center);
				open_queue.insert(it, priority);
			}
		}
		if (open_queue.size() == 0) {
			std::cout << "THE GRAPH IS NOT CONNECTED. "
					<< "WE COULD NOT COMPUTE THE SHORTEST PATH BETWEEN TWO OF THE NODES. "
					<< "WE HAVE GIVEN THE VALUE -1 TO THE LENGTH OF THIS PATH."
					<< endl << endl;
			return -1;
		}

		open_queue.priority_sort();

		center = open_queue.top();
		closed_queue.insert(center, open_queue.get_priority(center));

		open_queue.minPrioirty();
	}
	return closed_queue.get_priority(w);

}
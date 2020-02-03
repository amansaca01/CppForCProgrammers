/*
 * shortest_path.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#include "shortest_path.h"
#include "priority_queue.h"
#include "graph.h"
#include <vector>
#include <numeric> //iota
#include<iostream>
#include <algorithm>


ShortestPath::ShortestPath(const graph &G) :
		G(G) {
	int size = this->G.V();
	nodes_queues.resize(size, size);
}

std::vector<int> ShortestPath::vertices() {

	std::vector<int> lista(G.V());
	std::iota(lista.begin(), lista.end(), 0);
	return lista;
}

std::vector<int> ShortestPath::path(const int &u, const int &w) {

	std::vector<int> shortest_path = { w };


	int min_path = path_size(u, w);
	PriorityQueue closed_queue = nodes_queues.at(u);

	int center = w;
	if (min_path > 0) {

		while (center != u) {

			std::vector<int> adjacents = G.neighbors(center);
			auto next_node = adjacents.begin();

			while (next_node != adjacents.end() && *next_node != center) {
				if (!closed_queue.contains_node(*next_node)) {
					++next_node;
				} else {
					int nex_node_distance = closed_queue.get_priority(
							*next_node) + G.get_edge_value(center, *next_node);
					int center_priority = closed_queue.get_priority(center);
					if (center_priority == nex_node_distance
							&& center_priority >= 0) {
						center = *next_node;
						shortest_path.push_back(center);
					} else {
						++next_node;
					}
				}
			}
			if (next_node == adjacents.end()) {
				std::cout << "Reached end of list." << std::endl;
				return shortest_path;
			}
		}

	}

	return shortest_path;
}


int ShortestPath::path_size(const int &u, const int &w) {

	PriorityQueue closed_queue = nodes_queues.at(u);

	if (!closed_queue.contains_node(w))
		djistra_algo(u, w);

	return nodes_queues.at(u).get_priority(w); // returns -1 if the nodes are not connected

}

void ShortestPath::djistra_algo(const int &u, const int &w) {

	PriorityQueue open_queue(G.V());
	PriorityQueue* closed_queue = &nodes_queues.at(u);

	if (closed_queue->size() == 0)
		closed_queue->insert(u, 0);

	int center = closed_queue->tail();

	while (!closed_queue->contains_node(w)) {
		std::vector<int> adjacents = G.neighbors(center);
		for (int &it : adjacents) {
			if (!closed_queue->contains_node(it)) {

				int priority = G.get_edge_value(center, it)
						+ closed_queue->get_priority(center);

				open_queue.insert(it, priority);
			}
		}
		if (open_queue.size() == 0) {
			closed_queue->insert(w, -1);

			std::cout << "Nodes " << u << " and " << w
					<< " are not connected by any path." << std::endl;
			return;
		}

		open_queue.priority_sort();

		center = open_queue.top();
		closed_queue->insert(center, open_queue.get_priority(center));

		open_queue.minPrioirty();

	}

	closed_queue->priority_sort();

}


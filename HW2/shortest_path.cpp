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

bool ShortestPath::is_connected() {

	PriorityQueue closed_queue({0},G.V());
	PriorityQueue open_queue(G.neighbors(0),G.V());

	while (closed_queue.size() < G.V()) {

		if (open_queue.size() == 0) {
			return false;
		}

		int next_element = open_queue.top();
		auto adjacents = G.neighbors(next_element);

		for (auto &it : adjacents) {
			if (!closed_queue.contains_node(it))
				open_queue.insert(it);
			else {
				if (it == next_element)
					std::cout << "This graph has loops!" << std::endl;
			}
		}

		closed_queue.insert(next_element);
		open_queue.minPrioirty();
	}

	return true;
}


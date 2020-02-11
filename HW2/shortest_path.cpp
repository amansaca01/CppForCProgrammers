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
#include<iostream>
#include <algorithm>

ShortestPath::ShortestPath(const graph &G) :
		G(G) {
	int size = this->G.V();
	nodes_queues.resize(size, size);
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

graph ShortestPath::MST() {

	int n_nodes = G.V();
	graph min_tree(n_nodes, 0);

	if (!is_connected()) {
		std::cout << "The graph is not connected." << std::endl;
		return min_tree;
	}

	std::cout << n_nodes << std::endl;

	PriorityQueue node_set(n_nodes);
	PriorityQueue edge_queue(n_nodes * n_nodes + 1);

	int next_node = 0;
	pairs next_edge;

	while (node_set.size() < n_nodes) {

		node_set.insert(next_node);

		std::vector<int> adjacents = G.neighbors(next_node);

		for (auto &ad : adjacents) {
			if (!node_set.contains_node(ad)) {
				edge_queue.insert(G.get_edge_id(next_node, ad),
						G.get_edge_value(next_node, ad));
			}
		}
		edge_queue.priority_sort();

		next_edge = G.get_nodes(edge_queue.top());
		edge_queue.minPrioirty();

		next_node = next_edge.second;
		min_tree.add_edge(next_edge.first, next_node,
				G.get_edge_value(next_edge.first, next_node));
	}
	return min_tree;
}

bool ShortestPath::is_connected() {

	PriorityQueue closed_queue( { 0 }, G.V());
	PriorityQueue open_queue(G.neighbors(0), G.V());

	while (closed_queue.size() < G.V()) {
		int next_element = open_queue.top();

		if (open_queue.size() == 0) {
			return false;
		}

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


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

std::pair<int, graph> ShortestPath::MST() {

//std::pair<int, std::vector<pairs>> ShortestPath::MST() {

	int n_nodes = G.V();
	int cost=0;
	graph min_tree(n_nodes,0);


	if(!is_connected()){
	//	throw(std::runtime_error("The graph is not connected."));

		std::cout << "The graph is not connected." << std::endl;
		return std::make_pair(-1, min_tree);
	}

	PriorityQueue node_queue(n_nodes);
	PriorityQueue edge_queue(G.E());

	vector<vector<int>> edges_id(G.E());
	int id = 0;

	node_queue.insert(0,0);
	int next_node;

	while (node_queue.size() < n_nodes) {

		std::cout << next_node << " " << node_queue.get_priority(next_node)
				<< std::endl;
		std::vector<int> adjacents = G.neighbors(next_node);

		for(auto &ad : adjacents){
			edges_id.push_back(vector<int>{id,next_node,ad});
			if(!node_queue.contains_node(ad)){
				edge_queue.insert(ad, G.get_edge_value(next_node, ad));
			}
		}

		edge_queue.priority_sort();

		min_tree.add_edge(next_node, edge_queue.top(),
				G.get_edge_value(next_node, edge_queue.top()));

		int next_node_priority = edge_queue.get_priority(next_node);
		cost += next_node_priority;
		node_queue.insert(next_node,next_node_priority);
		next_node = edge_queue.top();
		edge_queue.minPrioirty();
	}
//	return std::make_pair(cost,edges_path);
	return std::make_pair(cost,min_tree);
}

bool ShortestPath::is_connected() {

	PriorityQueue closed_queue({0},G.V());
	PriorityQueue open_queue(G.neighbors(0),G.V());

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


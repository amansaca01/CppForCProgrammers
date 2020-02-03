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
	int size =this->G.V();
	nodes_queues.resize(size, size);
}

std::vector<int> ShortestPath::vertices() {

	std::vector<int> lista(G.V());
	std::iota(lista.begin(), lista.end(), 0);
	return lista;
}

std::vector<int> ShortestPath::path(const int &u, const int &w) {

	PriorityQueue closed_queue = nodes_queues.at(u);
	std::vector<int> shortest_path = {w};

	int min_path = path_size(u, w);

	int center = w;
	if(min_path>0){
	while(center!=u){
			std::vector<int> adjacents = G.neighbors(center);
			std::vector<int> priorities;
			for (auto &ad : adjacents) {
				if(closed_queue.contains_node(ad)){
					priorities.push_back(closed_queue.get_priority(ad));
				}
			}

			int min_pos = std::distance(priorities.begin(),
						std::min_element(priorities.begin(), priorities.end()));

				center =adjacents[min_pos];
				shortest_path.push_back(center);
		}
	}

	return shortest_path;

}

int ShortestPath::path_size(const int &u, const int &w) {

	PriorityQueue closed_queue = nodes_queues.at(u);

	if(!closed_queue.contains_node(w))
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

}


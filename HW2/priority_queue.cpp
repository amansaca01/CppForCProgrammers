/*
 * priority_queue.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#include "priority_queue.h"

#include <iostream>
#include<vector>
#include <algorithm>

#include "graph.h"

PriorityQueue::PriorityQueue(const graph &G) :
		G(G) {
}

void PriorityQueue::chgPrioirity(const int &node, const size_t &priority) {
	if (priority >= 0 && contains_node(node)) {
//		std::cout << "PQ: " << node << " " << priority << std::endl;
		G.set_node_value(node, priority);
	}
}

void PriorityQueue::minPrioirty() {
	node_queue.erase(node_queue.begin());
}

bool PriorityQueue::contains_node(const int &node) {
	return std::find(node_queue.begin(), node_queue.end(), node)
			!= node_queue.end();
}
void PriorityQueue::insert(const int &node, const size_t &priority) {
	if (!contains_node(node)) {
		node_queue.push_back(node);
		chgPrioirity(node, priority);
	} else {
		if (get_priority(node) > priority)
			chgPrioirity(node, priority);
	}
}

int PriorityQueue::top() {
	return node_queue.front();
}

int PriorityQueue::size() {
	return node_queue.size();
}

int PriorityQueue::get_priority(const int &node) {
	return G.get_node_value(node);
}

void PriorityQueue::priority_sort() {

	std::sort(node_queue.begin(), node_queue.end(),
			[this](int i, int j) {return get_priority(i)<get_priority(j);});

}

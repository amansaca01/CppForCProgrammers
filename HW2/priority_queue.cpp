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

PriorityQueue::PriorityQueue() {
	// TODO Auto-generated constructor stub

}

void PriorityQueue::minPrioirty() {
	node_queue.erase(node_queue.begin());
}

bool PriorityQueue::contains_node(const int &node) {
	return std::find(node_queue.begin(), node_queue.end(), node)
			!= node_queue.end();
}
void PriorityQueue::insert(const int &node) {
	if (!contains_node(node))
		node_queue.push_back(node);
	else std::cout << "Node " << node << " is already on the queue!";
}

int PriorityQueue::top(const int &node) {
	return node_queue.front();
}

int PriorityQueue::size() {
	return node_queue.size();
}

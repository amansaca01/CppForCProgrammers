/*
 * priority_queue.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: andrea.yuste
 */

#include "priority_queue.h"

#include <algorithm>

// PROPOSED METHODS

PriorityQueue::PriorityQueue(const graph &G) :
		priority(priority), queue_element(queue_element), G(G) {
}

// Changes the priority (node value) of queue element.
void PriorityQueue::chgPrioirity(const int &priority) {
	G.set_node_value(queue_element, priority);
}

// Removes the top element of the queue.
void PriorityQueue::minPrioirty() {
	nodes_queue.erase(nodes_queue.begin());
}

// Does the queue contain queue_element.
bool PriorityQueue::contains(const int &queue_element) {
	return std::find(nodes_queue.begin(), nodes_queue.end(), queue_element)
			!= nodes_queue.end();
}

// Insert queue_element into queue
void PriorityQueue::Insert(const int &queue_element) {
	nodes_queue.push_back(queue_element);
}

// Returns the top element of the queue.
int PriorityQueue::top() {
	return nodes_queue.front();
}

// Returns the number of queue_elements.
int PriorityQueue::size() {
	return nodes_queue.size();
}

// ADITIONAL METHODS

void PriorityQueue::chgPrioirity(const int &node, const size_t &priority) {
	// std::size_t can store the maximum size of a theoretically possible object of any type
	if (priority >= 0 && contains(node)) {
		G.set_node_value(node, priority);
	}
}

void PriorityQueue::insert(const int &node, const size_t &priority) {
	if (!contains(node)) {
		nodes_queue.push_back(node);
		chgPrioirity(node, priority);
	} else {
		if (get_priority(node) > priority)
			chgPrioirity(node, priority);
	}
}

int PriorityQueue::get_priority(const int &node) {
	return G.get_node_value(node);
}

void PriorityQueue::priority_sort() {
	std::sort(nodes_queue.begin(), nodes_queue.end(),
			[this](int i, int j) {return get_priority(i)<get_priority(j);});

}

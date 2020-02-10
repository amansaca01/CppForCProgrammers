/*
 * priority_queue.h
 *
 *  Created on: Jan 29, 2020
 *      Author: andrea.yuste
 *
 *      The value of the PriorityQueue is to always have access to the vertex with the next shortest link
 *      in the shortest path calculation at the top of the queue.
 */

#ifndef INCLUDE_PRIORITY_QUEUE_H_
#define INCLUDE_PRIORITY_QUEUE_H_

#include "graph.h"

class PriorityQueue {

public:
	// Proposed methods
	PriorityQueue(const Graph &G);
	virtual ~PriorityQueue() = default;

	void chgPrioirity(const int &priority); //changes the priority (node value) of queue element.
	void minPrioirty(); //removes the top element of the queue.
	bool contains(const int &queue_element); //does the queue contain queue_element.
	void Insert(const int &queue_element); //insert queue_element into queue
	int top(); //returns the top element of the queue.
	int size(); //returns the number of queue_elements.

	// Additional methods
	void chgPrioirity(const int &node, const int &priority); //changes the priority of queue element.
	void insert(const int &node, const int &priority); //insert queue_element into queue (last position)
	int get_priority(const int &node); //return the node priority
	void priority_sort(); //sorts nodes_queue by priority

	// Public elements ~
	std::vector<int> nodes_queue; // Queue of nodes

private:
	// Proposed elements
	int priority;
	int queue_element;

	// Additional elements
	Graph G; // graph on which the algorithm is being run
};

#endif /* INCLUDE_PRIORITY_QUEUE_H_ */

/*
 * shortest_path.h
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#ifndef HW2_SHORTEST_PATH_H_
#define HW2_SHORTEST_PATH_H_

#include "graph.h"
#include "priority_queue.h"

class ShortestPath {
public:
	ShortestPath(const graph &G);
	virtual ~ShortestPath() = default;
	int path_size(const int &u, const int &w); //return the path cost associated with the shortest path
	void djistra_algo(const int &u, const int &w); //computes de Djistra algorithm
	graph MST(); // Prims minumum expanning tree, returns const and vector of edges.
	bool is_connected();

private:
	graph G; // graph on which the algorithm is being run

	std::vector<PriorityQueue> nodes_queues; //qeues un nodes in the closed set
};

#endif /* HW2_SHORTEST_PATH_H_ */

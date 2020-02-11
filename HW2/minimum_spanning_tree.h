/*
 * minimum_spanning_tree.h
 *
 *  Created on: Feb 7, 2020
 *  Author: andrea.yuste
 */

#ifndef INCLUDE_MINIMUM_SPANNING_TREE_H_
#define INCLUDE_MINIMUM_SPANNING_TREE_H_

#include "graph.h"
#include "priority_queue.h"

class MinimumSpanningTree {
public:
	MinimumSpanningTree(const Graph &G);
	virtual ~MinimumSpanningTree() = default;

	int Cost(Graph G);

private:
	Graph G; // graph on which the algorithm is being run
};

#endif /* INCLUDE_MINIMUM_SPANNING_TREE_H_ */

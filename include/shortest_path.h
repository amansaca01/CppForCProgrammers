/*
 * shortest_path.h
 *
 *  Created on: Jan 29, 2020
 *      Author: andrea.yuste
 */

#ifndef INCLUDE_SHORTEST_PATH_H_
#define INCLUDE_SHORTEST_PATH_H_

#include "graph.h"

// The class ShortestPathAlgo implements the mechanics of Dijkstra’s algorithm.
// Besides having member fields (has a relationship) of Graph and Priority Queue,
// an additional ADT maybe required to maintain the parent relationship of the shortest path.

class ShortestPath {

public:
	// Proposed methods
	ShortestPath(const graph &G);
	virtual ~ShortestPath() = default;

	std::vector<int> vertices(); //list of vertices in G(V,E)
	std::vector<int> path(const int &u, const int &w); //find shortest path between u-w and returns the sequence of vertices representing shortest path u-v1-v2-...-n-w.
	int path_size(const int &u, const int &w); //return the path cost associated with the shortest path

private:
	graph G; // graph on which the algorithm is being run
};

#endif /* INCLUDE_SHORTEST_PATH_H_ */

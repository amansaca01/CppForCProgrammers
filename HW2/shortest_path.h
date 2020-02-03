/*
 * shortest_path.h
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#ifndef HW2_SHORTEST_PATH_H_
#define HW2_SHORTEST_PATH_H_

#include "graph.h"

class ShortestPath {

public:
	ShortestPath(const graph &G);
	virtual ~ShortestPath() = default;
	std::vector<int> vertices(); //list of vertices in G(V,E)
	std::vector<int> path(const int &u, const int &w); //find shortest path between u-w and returns the sequence of vertices representing shorest path
	int path_size(const int &u, const int &w); //return the path cost associated with the shortest path

private:
	graph G; // graph on which the algorithm is being run
};

#endif /* HW2_SHORTEST_PATH_H_ */

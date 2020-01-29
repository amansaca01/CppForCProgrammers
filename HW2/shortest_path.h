/*
 * shortest_path.h
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#ifndef HW2_SHORTEST_PATH_H_
#define HW2_SHORTEST_PATH_H_

#include "graph.h"

namespace std {

class ShortestPath {
public:
	ShortestPath();
	virtual ~ShortestPath() = default;
	std::vector<int> vertices(const graph &G);
private:
	graph G; // graph on which the algorithm is being run
};

} /* namespace std */

#endif /* HW2_SHORTEST_PATH_H_ */

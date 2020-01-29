/*
 * shortest_path.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#include "shortest_path.h"

ShortestPath::ShortestPath(const graph &G) :
		G(G) {
}


std::vector<int> ShortestPath::vertices(const graph &G) {
	std::vector<int> vertices(G.V());
	return std::iota(vertices.begin(),vertices.end,0);
}

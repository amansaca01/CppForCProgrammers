/*
 * shortest_path.cpp
 *
 *  Created on: Jan 29, 2020
 *      Author: amanda.salazar
 */

#include "shortest_path.h"
#include "priority_queue.h"
#include "graph.h"
#include <vector>
#include <numeric> //iota

ShortestPath::ShortestPath(const graph &G) :
		G(G) {
}

std::vector<int> ShortestPath::vertices() {

	std::vector<int> lista(G.V());
	std::iota(lista.begin(), lista.end(), 0);
	return lista;
}

std::vector<int> ShortestPath::path(const int &u, const int &w) {

	PriorityQueue path_queue(G);
	path_queue.insert(u,0);

	int center = u;
	std::vector<int> adjacents = G.neighbors(center);
	return adjacents;

}

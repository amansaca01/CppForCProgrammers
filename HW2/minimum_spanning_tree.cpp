/*
 * minimum_spanning_tree.cpp
 *
 * 	Created on : Feb 7, 2020
 * 	Author : andrea.yuste
 */

#include "minimum_spanning_tree.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

MinimumSpanningTree::MinimumSpanningTree(const Graph & G) :
		G(G) {
}

// Returns the cost of the MST calculated with Prim's algorithm.
int MinimumSpanningTree::Cost(Graph G) {

	std::vector<int> costs;
	// Start at node zero
	int node = 0;
	PriorityQueue closed_set(G);

	while (closed_set.nodes_queue.size() < G.size) {

		if (!closed_set.contains(node))
			closed_set.Insert(node);

		// Recover node neighbors
		std::vector<int> neighbors = G.neighbors(node);

		// Compute the distance to each of the neighbors of the node
		std::vector<int> distances;
		for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
			int d = G.get_edge_value(node, *it);
			distances.push_back(d);
		}

		// We look for the node with less distance
		int min_distance = *std::min_element(distances.begin(),
				distances.end());

		std::vector<int>::iterator it = std::find(distances.begin(),
				distances.end(), min_distance);
		int min_distance_index = std::distance(distances.begin(), it);
		int closest_node = neighbors.at(min_distance_index);

		// We keep the node with less distance if it is not in the closed set
		if (!closed_set.contains(closest_node)) {
			costs.push_back(min_distance);
			node = closest_node;
		}
		// If the node is in the closed set, we delete the edge so we do not find it again
		else {
			G.delete_edge(node, closest_node);
		}
	}

	cout << "The reduced graph is:" << endl;
	G.print_graph();
	cout << endl;

	cout << "The tree reaches the nodes in the following order: " << endl;
	for (std::vector<int>::const_iterator i = closed_set.nodes_queue.begin();
			i != closed_set.nodes_queue.end(); ++i)
		std::cout << *i << " ";
	cout << "\n" << endl;

	cout << "The edge costs (weights) in the spanning tree are: " << endl;
	for (std::vector<int>::const_iterator i = costs.begin(); i != costs.end();
			++i)
		std::cout << *i << " ";
	cout << "\n" << endl;

	int cost = accumulate(costs.begin(), costs.end(), 0);
	cout << "The cost of such a spanning tree is: " << cost << endl;

	return cost;
}

/*
 * graph.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: andrea.yuste
 */

#include "graph.h"

graph::graph(const int &size, const float &density, const int &range) :
		size(size), range(range) {

	ad_matrix = new int*[size];

	for (int i = 0; i < size; ++i) {

		nodes_values.push_back(i + 1);
		ad_matrix[i] = new int[size];

		// We assume that there is no edge that goes from a node to itself
//		ad_matrix[i][i] = 0;
		delete_edge(0, 0);

		for (int j = 0; j < i; ++j) {
			// We place an edge in the graph if a random probability calculation is less than the density
			if (prob() < density) {
				add_edge(i, j);
			} else {
//				ad_matrix[i][j] = 0;
//				ad_matrix[j][i] = 0;
				delete_edge(i, j);
			}
		}
	}
}

// PROPOSED METHODS
// Returns the number of vertices in the graph
int graph::V() {
	return size;
}

// Returns the number of edges in the graph
int graph::E() {
	int edges = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (adjacent(i, j))
				edges++;
		}
	}
	return edges;
}

// Tests whether there is an edge from node x to node y
bool graph::adjacent(const int &x, const int &y) {
	return ad_matrix[x][y] != 0;
}

// Lists all nodes y such that there is an edge from x to y
std::vector<int> graph::neighbors(const int &x) {
	std::vector<int> adjacents;
	for (int i = 0; i < size; ++i) {
		if (adjacent(x, i))
			adjacents.push_back(i);
	}
	return adjacents;
}

// Adds to G the edge from x to y, if it is not there
void graph::add_edge(const int &x, const int &y) {
	if (!adjacent(x, y)) {
		// The edge distance would be selected at random from the distance range
		int distance = (rand() % (range - 1)) + 1;
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

// Removes the edge from x to y, if it is there
void graph::delete_edge(const int &x, const int &y) {
	if (adjacent(x, y)) {
		ad_matrix[x][y] = 0;
		ad_matrix[y][x] = 0;
	}
}

// Returns the value associated with the node x
int graph::get_node_value(const int &x) {
	if (x >= 0 && x < size)
		return nodes_values.at(x);
	return -1; //if x is not a node
}

// Sets the value associated with the node x to a
void graph::set_node_value(const int &x, const int &a) {
	if (x >= 0 && x < size && a >= 0 && a < size)
		nodes_values.at(x) = a;
}

// Returns the value associated to the edge (x,y)
int graph::get_edge_value(const int &x, const int &y) {
	if (adjacent(x, y))
		return ad_matrix[x][y];
	return -1; //if there is no edge
}

// Sets the value associated to the edge (x,y) to distance
void graph::set_edge_value(const int &x, const int &y, const int &distance) {
	if (adjacent(x, y) && distance > 0 && distance <= range) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

// ADITIONAL METHODS

// Returns random number between o and 1
float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

// Returns random distance in between the distance range
int graph::distance(const int &range) {
	return (rand() % (range - 1)) + 1;
}

// Print the graph connectivity matrix on the screen
void graph::print_graph() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << ad_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

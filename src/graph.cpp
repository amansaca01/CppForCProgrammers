/*
 * graph.cpp
 *
 *  Created on: Jan 27, 2020
 *  Author: andrea.yuste
 */

#include "../include/graph.h"

using namespace std;

// Constructor that generates a random graph
Graph::Graph(const int& size, const float& density, const int& range) :
		size(size), range(range) {

	// Create the connectivity matrix
	ad_matrix = vector<vector<int>>(size, vector<int>(size, 0));

	// Fill in the connectivity matrix
	for (int i = 0; i < size; ++i) {

		// Fill in the node vector
		nodes_values.push_back(i + 1);

		// We assume that there is no edge that goes from a node to itself
		delete_edge(i, i);

		for (int j = i + 1; j < size; ++j) {
			// We place an edge in the graph if a random probability calculation is less than the density
			if (prob() < density) {
				add_edge(i, j);
			} else {
				delete_edge(i, j);
			}
		}
	}
}

// Constructor that can read in a graph from a file
Graph::Graph(const string& filename) :
		filename(filename) {

	ifstream dataf(filename);
	if (!dataf.is_open()) {
		throw(std::runtime_error("Unable to open file"));
	}

	string line;

	getline(dataf, line);
	stringstream ss;
	ss << line;
	ss >> size;

	// Initializes adjacent matrix with 0s
	ad_matrix.resize(size, std::vector<int>(size, 0));

	int num1, num2, num3;
	while (getline(dataf, line)) {
		stringstream ss;
		ss << line;
		ss >> num1 >> num2 >> num3;
		int x = num1;
		int y = num2;
		int distance = num3;
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

// PROPOSED METHODS

// Returns the number of vertices in the graph
int Graph::V() {
	return size;
}

// Returns the number of edges in the graph
int Graph::E() {
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
bool Graph::adjacent(const int& x, const int& y) {
	return ad_matrix[x][y] != 0;
}

// Lists all nodes y such that there is an edge from x to y
std::vector<int> Graph::neighbors(const int& x) {
	std::vector<int> adjacents;
	for (int i = 0; i < size; ++i) {
		if (adjacent(x, i))
			adjacents.push_back(i);
	}
	return adjacents;
}

// Adds to G the edge from x to y, if it is not there
void Graph::add_edge(const int& x, const int& y) {
	// The edge distance would be selected at random from the distance range
	int distance = (rand() % (range - 1)) + 1;
	ad_matrix[x][y] = distance;
	ad_matrix[y][x] = distance;
}

// Removes the edge from x to y, if it is there
void Graph::delete_edge(const int& x, const int& y) {
	ad_matrix[x][y] = 0;
	ad_matrix[y][x] = 0;
}

// Returns the value associated with the node x
int Graph::get_node_value(const int& x) {
	if (x >= 0 && x < size)
		return nodes_values.at(x);
	return -1; //if x is not a node
}

// Sets the value associated with the node x to a
void Graph::set_node_value(const int& x, const int& a) {
	if (x >= 0 && x < size && a >= 0 && a < size)
		nodes_values.at(x) = a;
}

// Returns the value associated to the edge (x,y)
int Graph::get_edge_value(const int& x, const int& y) {
	if (adjacent(x, y))
		return ad_matrix[x][y];
	return -1; //if there is no edge
}

// Sets the value associated to the edge (x,y) to distance
void Graph::set_edge_value(const int& x, const int& y, const int& distance) {
	if (adjacent(x, y) && distance > 0 && distance <= range) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

// ADDITIONAL METHODS

// Returns random number between o and 1
float Graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

// Returns random distance in between the distance range
int Graph::distance(const int& range) {
	return (rand() % (range - 1)) + 1;
}

// Print the graph connectivity matrix on the screen
void Graph::print_graph() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << ad_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

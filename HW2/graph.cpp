/*
 * graph.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: amanda.salazar
 */

#include "graph.h"
#include<iostream>
#include<vector>

using namespace std;

graph::graph(const int &size, const float &density, const int &range) :
		size(size), range(range) {

	ad_matrix = new int*[size];

	for (int i = 0; i < size; ++i) {

		node_value.push_back(i + 1);

		ad_matrix[i] = new int[size];

// We assume that there is no edge that goes from a node to itself.
		ad_matrix[i][i] = 0;

		for (int j = 0; j < i; ++j) {

// We place an edge in the graph if a random probability calculation is less than the density
			if (prob() < density) {

// The edge distance would be selected at random from the distance range
				int distance = (rand() % (range - 1)) + 1;
				ad_matrix[i][j] = distance;
				ad_matrix[j][i] = distance;

			} else {
				ad_matrix[i][j] = 0;
				ad_matrix[j][i] = 0;
			}
		}
	}
}

float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

int graph::prob(const int &range) {
	return (rand() % range) + 1;
}

int graph::V() {
	return size;
}
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

bool graph::adjacent(const int &x, const int &y) {
	return ad_matrix[x][y] != 0;
}

std::vector<int> graph::neighbors(const int &x) {
	std::vector<int> adjacents;
	for (int i = 0; i < size; ++i) {
		if (adjacent(x, i))
			adjacents.push_back(i);
	}
	return adjacents;
}

void graph::add_edge(const int &x, const int &y) {
	add_edge(x, y, prob(range));
}

void graph::add_edge(const int &x, const int &y, const int &distance) {
	if (!adjacent(x, y) && x != y && distance <= range && distance >= 1) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

void graph::delete_edge(const int &x, const int &y) {
	if (adjacent(x, y)) {
		ad_matrix[x][y] = 0;
		ad_matrix[y][x] = 0;
	}
}

int graph::get_node_value(const int &x) {
	if (x >= 0 && x < size)
		return node_value.at(x);
	return -1; // returns 0 if x is not a node
}

void graph::set_node_value(const int &x, const int &a) {
	if (a >= 0 && x >= 0 && x < size)
		node_value.at(x) = a;
}

int graph::get_edge_value(const int &x, const int &y) {
	if (adjacent(x, y))
		return ad_matrix[x][y];
	return 0; // returns 0 if there is no edge
}

void graph::set_edge_value(const int &x, const int &y, const int &distance) {
	if (adjacent(x, y) && distance <= range && distance >= 1) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

void graph::print_graph() {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << ad_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

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

graph::graph(const int &size, const float &density, const pairs &range) :
		size(size), density(density), range(range) {

	// TODO: tiene sentido declarar esto aqui?
	srand(time(0));

	ad_matrix = new int*[size];

	for (int i = 0; i < size; ++i) {
		nodes_value.push_back(i + 1);
		ad_matrix[i] = new int[size];
		for (int j = 0; j < i; ++j) {
			if (prob() < density) {
				add_edge(i, j);
			}
		}
	}
}

float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

int graph::prob(const pairs &range) {
	int total_range = range.second - range.first + 1;
	return (rand() % total_range) + range.first;
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

bool graph::adjacent(int x, int y) {
	return ad_matrix[x][y] != 0;
}

std::vector<int> graph::neighbors(int x) {
	std::vector<int> adjacents;
	for (int i = 0; i < size; ++i) {
		if (adjacent(x, i))
			adjacents.push_back(i);
	}
	return adjacents;
}

void graph::add_edge(int x, int y) {
	add_edge(x, y, prob(range));
}

void graph::add_edge(int x, int y, int distance) {
	if (!adjacent(x, y) && x != y && distance <= range.second
			&& distance >= range.first) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;
	}
}

void graph::delete_edge(int x, int y) {
	if (adjacent(x, y)) {
		ad_matrix[x][y] = 0;
		ad_matrix[y][x] = 0;
	}
}

int graph::get_node_value(int x) {
	if (x < size)
		return nodes_value.at(x);
	return -1; // returns -1 if x is not a node
}

void graph::set_node_value(int x, int a) {
	if (a >= 0)
		nodes_value.at(x) = a;
}

int graph::get_edge_value(int x, int y) {
	if (adjacent(x, y))
		return ad_matrix[x][y];
	return -1; // returns -1 if there is no edge
}

void graph::print_graph() {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << ad_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

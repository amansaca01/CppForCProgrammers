/*
 * graph.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: amanda.salazar
 */

#include "graph.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<iterator>

using namespace std;

graph::graph(const int &size, const float &density, const pairs &range) :
		size(size), range(range) {

	ad_matrix.resize(size, std::vector<int>(size, 0)); // initializes adjacents matrix with 0s
	nodes_value.resize(size, 0);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (prob() < density) {
				add_edge(i, j);
			}
		}
	}
}


graph::graph(const string file_name, const pairs &range) :
		range(range) {

	ifstream data_file(file_name);

	if (!data_file.is_open()) {
		throw(std::runtime_error("Unable to open file."));
	}

	data_file >> size;

	ad_matrix.resize(size, std::vector<int>(size, 0)); // initializes adjacents matrix with 0s
	nodes_value.resize(size, 0);

	int x, y, distance;
	while (!data_file.eof()) {
		data_file >> x >> y >> distance;
		add_edge(x, y, distance);
	}

}

graph::graph(const std::vector<pairs> edges, const graph &origin,
		const pairs &range) {

	size = origin.V();

	ad_matrix.resize(size, std::vector<int>(size, 0)); // initializes adjacents matrix with 0s
	nodes_value.resize(size, 0);

	for (auto &edge : edges) {
		add_edge(edge.first, edge.second,
				origin.get_edge_value(edge.first, edge.second));
	}
}

float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

int graph::prob_int(const pairs &range) {
	int total_range = range.second - range.first + 1;
	return (rand() % total_range) + range.first;
}

int graph::V() const{
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

bool graph::adjacent(const int &x, const int &y) const {
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
	add_edge(x, y, prob_int(range));
}

void graph::add_edge(const int &x, const int &y, const int &distance) {
	if (!adjacent(x, y) && x != y) {
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
		return nodes_value.at(x);
	return -1; // returns 0 if x is not a node
}

void graph::set_node_value(const int &x, const int &a) {
	if (a >= 0 && x >= 0 && x < size)
		nodes_value.at(x) = a;
}

int graph::get_edge_value(const int &x, const int &y) const {
	if (adjacent(x, y))
		return ad_matrix[x][y];
	return 0; // returns 0 if there is no edge
}

void graph::set_edge_value(const int &x, const int &y, const int &distance) {
	if (adjacent(x, y)) {
		ad_matrix[x][y] = distance;
		ad_matrix[y][x] = distance;

	}
}

bool graph::is_looped() {
	for (int i = 0; i < size; ++i) {
		if (ad_matrix[i][i] != 0)
			return false;
	}
	return true;
}

void graph::print_graph() {

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << ad_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

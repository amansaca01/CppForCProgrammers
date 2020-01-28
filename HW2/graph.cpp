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

	ad_matrix.resize(size, vector<int>(size));

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (prob() < density) {
				ad_matrix[i][j] = ad_matrix[j][i] = prob(range);
				edges++;
			}
		}
	}
}

float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

int graph::prob(const pairs &range) {
	return prob(range.first, range.second);
}

int graph::prob(const int &lower_range, const int &upper_range) {
	int total_range = upper_range - lower_range;
	return (rand() % total_range) + lower_range;

}

int graph::V() {
	return size ^ 2;
}
int graph::E() {
	return edges;
}

bool graph::adjacent(int x, int y) {
	return ad_matrix[x][y]!=0;
}

std::vector<int> graph::neighbors(int x){
	std::vector<int> adjacents;
	for (int i = 0; i < size; ++i) {
		if (adjacent(x,i)) adjacents.push_back(i);
	}
	return adjacents;
}
void graph::print_graph() {

	for (auto col = ad_matrix.begin(); col != ad_matrix.end(); ++col) {
		for (auto row = col->begin(); row != (*col).end(); ++row) {
			cout << *row;
		}
		cout << endl;
	}
}

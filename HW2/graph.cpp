/*
 * graph.cpp
 *
 *  Created on: Jan 27, 2020
 *      Author: amanda.salazar
 */

#include "graph.h"
#include<iostream>

graph::graph(const int &size, const float &density, const int &lower_range,
		const int &upper_range) :
		size(size), density(density), lower_range(lower_range), upper_range(
				upper_range) {

	// TODO: tiene sentido declarar esto aqui?
	srand(time(0));

	ad_matrix = new int*[size];
	for (int i = 0; i < size; ++i) {
		ad_matrix[i] = new int[size];
	}

	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (i == j || prob() >= density)
				ad_matrix[i][j] = 0;
			else {
				ad_matrix[i][j] = ad_matrix[j][i] = prob(lower_range, upper_range);
			}
		}
	}

}

float graph::prob() {
	return rand() / static_cast<float>(RAND_MAX);
}

int graph::prob(const int &lower_range, const int &upper_range) {
	int total_range = upper_range - lower_range;
	return (rand() % total_range) + lower_range;

}

void graph::print_graph() {

	for (int i = 0; i < size; ++i) {

		for (int j = 0; j < size; ++j) {
			std::cout << ad_matrix[i][j];
		}
		std::cout << std::endl;

	}
}

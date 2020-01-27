/*
 * graph.h
 *
 *  Created on: Jan 27, 2020
 *      Author: amanda.salazar
 */

#ifndef GRAPH_H_
#define GRAPH_H_

class graph {
public:
	graph(const int &size = 1, const float &density = 0, const int &lower_range =
			1, const int &upper_range = 10);
	virtual ~graph() = default;
	char are_connected(int i, int j) {
		return ad_matrix[i][j];
	}
	float prob();
	int prob(const int &lower_range, const int &upper_range);
	void print_graph();

private:
	int** ad_matrix;
	int size;
	float density;
	int lower_range;
	int upper_range;
};

#endif /* GRAPH_H_ */

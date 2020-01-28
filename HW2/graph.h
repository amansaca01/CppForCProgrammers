/*
 * graph.h
 *
 *  Created on: Jan 27, 2020
 *      Author: amanda.salazar
 */

#include<vector>

#ifndef GRAPH_H_
#define GRAPH_H_

typedef std::pair<int, int> pairs;

class graph {
public:
	graph(const int &size = 1, const float &density = 0, const pairs &range =
			std::make_pair(1, 10));
	virtual ~graph() = default;
	char are_connected(int i, int j) {
		return ad_matrix[i][j];
	}
	float prob();
	int prob(const int &lower_range, const int &upper_range);
	int prob(const pairs &range);
	int V() ; //returns the number of vertices in the graph
	int E(); //returns the number of edges in the graph
	bool adjacent(int x, int y);
	std::vector<int> neighbors(int x);
	void print_graph();


private:
	std::vector<std::vector<int> > ad_matrix; // connectivity matrices are used
	int size;
	float density;
	pairs range;
	int edges;
};

#endif /* GRAPH_H_ */

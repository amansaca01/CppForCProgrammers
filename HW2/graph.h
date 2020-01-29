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

	float prob();
	int prob(const pairs &range);
	int V(); //returns the number of vertices in the graph
	int E(); //returns the number of edges in the graph
	bool adjacent(int x, int y); //tests whether there is an edge from node x to node y.
	std::vector<int> neighbors(int x); //lists all nodes y such that there is an edge from x to y.
	void add_edge(int x, int y); //adds the edge from x to y, if it is not there
	void add_edge(int x, int y, int distance); //adds the edge from x to y a certain distance
	void delete_edge(int x, int y); //removes the edge from x to y, if it is there.
	int get_node_value(int x); // returns the value associated with the node x.
	void set_node_value(int x, int a); //sets the value associated with the node x to a.
	int get_edge_value(int x, int y); //returns the value associated to the edge (x,y).
	void set_edge_value(int x, int y,int distance); //sets the value associated to the edge (x,y) to v.
	void print_graph();

private:
	bool** ad_matrix; // connectivity matrices are used
	std::vector<int> nodes_value;
	std::vector<std::vector<int>> edges_value;
	int size; // number of nodes
	float density;
	pairs range; // pair containing upper and lower edges distance range
};

#endif /* GRAPH_H_ */

/*
 * graph.h
 *
 *  Created on: Jan 27, 2020
 *  Author: andrea.yuste
 */

#ifndef INCLUDE_GRAPH_H_
#define INCLUDE_GRAPH_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Graph {

public:
	Graph(const int &size = 1, const float &density = 0, const int &range = 10);
	Graph(const string& filename);
	virtual ~Graph() = default;

	// Proposed methods
	int V(); //returns the number of vertices in the graph.
	int E(); //returns the number of edges in the graph.
	bool adjacent(const int &x, const int &y); //tests whether there is an edge from node x to node y.
	vector<int> neighbors(const int &x); //lists all nodes y such that there is an edge from x to y.
	void add_edge(const int &x, const int &y); //adds to G the edge from x to y, if it is not there.
	void delete_edge(const int &x, const int &y); //removes the edge from x to y, if it is there.
	int get_node_value(const int &x); //returns the value associated with the node x.
	void set_node_value(const int &x, const int &a); //sets the value associated with the node x to a.
	int get_edge_value(const int &x, const int &y); //returns the value associated to the edge (x,y).
	void set_edge_value(const int &x, const int &y, const int &distance); //sets the value associated to the edge (x,y) to v.

	// Additional methods
	float prob(); //
	int distance(const int &range);
	void print_graph();

	// Public elements
	int size = 0; //number of nodes

private:
	vector<vector<int>> ad_matrix; //connectivity matrix
	vector<int> nodes_values; //keeps the values associated with the node x
	int range = 0; //upper edges distance range

	string filename;
};

#endif /* INCLUDE_GRAPH_H_ */

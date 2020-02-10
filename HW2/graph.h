/*
 * graph.h
 *
 *  Created on: Jan 30, 2020
 *      Author: diego.gozalo
 */

#include<vector>
#include <string>
#include <fstream>
#include<iostream>
#include <sstream>

using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

typedef pair<int, int> pairs;

class graph {
public:
	graph(const int &size = 1, const float &density = 0, const pairs &range =
			make_pair(1, 10));
	graph(const string& filename);
	virtual ~graph() = default;

	float prob();
	int prob(const pairs &range);
	int V(); //returns the number of vertices in the graph
	int E(); //returns the number of edges in the graph
	bool adjacent(const int &x, const int &y); //tests whether there is an edge from node x to node y.
	vector<int> neighbors(const int &x); //lists all nodes y such that there is an edge from x to y.
	void add_edge(const int &x, const int &y); //adds the edge from x to y, if it is not there
	void add_edge(const int &x, const int &y, const int &distance); //adds the edge from x to y a certain distance
	void delete_edge(const int &x, const int &y); //removes the edge from x to y, if it is there.
	int get_node_value(const int &x); // returns the value associated with the node x.
	void set_node_value(const int &x, const int &a); //sets the value associated with the node x to a.
	int get_edge_value(const int &x, const int &y); //returns the value associated to the edge (x,y).
	void set_edge_value(const int &x, const int &y, const int &distance); //sets the value associated to the edge (x,y) to v.
	void print_graph();

private:  //can be accessed only through methods of the class
	vector<vector<int>> ad_matrix; // connectivity matrices are used
	//std::vector<int> nodes_value;
	int size; // number of nodes
	pairs range; // pair containing upper and lower edges distance range
	string filename;
};

#endif /* GRAPH_H_ */

/*
 * main.cpp
 *
 * 	Created on : Feb 7, 2020
 * 	Author : andrea.yuste
 */

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "graph.h"
#include "minimum_spanning_tree.h"

using namespace std;

int main() {

	// Read in a graph from a file
	Graph G(
			"/home/andrea.yuste/git/CppForCProgrammers/HW2/sample_test_data.txt");
	cout << "The graph read from the file is:" << endl;
	G.print_graph();
	cout << endl;

	// Compute a Minimum Spanning Tree for this graph
	MinimumSpanningTree MST(G);
	MST.Cost(G);

	return 0;
}

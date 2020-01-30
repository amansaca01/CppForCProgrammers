#include<iostream>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;


int main() {

	graph G(5,0.5);

	G.print_graph();

	G.set_node_value(1,12);

	cout << endl << G.adjacent(1,0) << " " << G.get_node_value(1) <<endl ;

	cout << ShortestPath(G).vertices().size() <<endl;
	return 0;
}

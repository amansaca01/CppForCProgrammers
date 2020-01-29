#include<iostream>

#include "graph.h"

using namespace std;


int main() {

	graph grafo(5,1);

	grafo.print_graph();

	grafo.set_node_value(1,12);

	cout << endl << grafo.E() << " " << grafo.get_node_value(1) ;
	return 0;
}

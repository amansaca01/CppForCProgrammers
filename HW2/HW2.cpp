#include<iostream>

#include "graph.h"

using namespace std;


int main() {

	graph grafo(5,0.75);

	grafo.print_graph();

	cout << grafo.neighbors(1)[2];
	return 0;
}

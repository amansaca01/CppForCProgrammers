#include<iostream>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(123);

	graph G(5, 1);

	G.print_graph();

	G.set_node_value(1, 12);

	//cout << endl << G.neighbors(1) << " " << G.get_node_value(1) << endl;

	auto elementos = G.neighbors(1);
//
//	for (auto i = elementos.begin(); i != elementos.end(); ++i)
//		cout << *i << endl;
	cout << endl;
//	cout << ShortestPath(G).vertices().size() << endl;

	ShortestPath camino(G);
	int lon = camino.path_size(1, 3);

	cout << endl << lon << endl;

	return 0;
}

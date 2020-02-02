#include<iostream>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(123);

	graph G(5, 0.5);

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
	int lon2 = camino.path_size(1, 4);
	int lon3 = camino.path_size(2, 1);

	camino.path(1,4);
	//cout << endl << lon << " " << lon2 << endl;

	return 0;
}

#include<iostream>
#include <numeric>


#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(123);

	int nodes_no = 5;
	graph G(nodes_no , 0.2);

	G.print_graph();

	ShortestPath djisktra(G);

	vector<int> paths;

	for (int i = 1; i < nodes_no ; ++i) {
		int lon = djisktra.path_size(0, i);
		if(lon>=1){
			paths.push_back(lon);
			cout << i << " "<< lon << endl;
		}
	}

	cout << endl << accumulate( paths.begin(), paths.end(), 0.0)/paths.size() <<endl;


	return 0;
}

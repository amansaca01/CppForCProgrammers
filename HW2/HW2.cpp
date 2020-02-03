#include<iostream>
#include <numeric>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(time(0));

	int nodes_no = 50;

	for (auto &density : vector<float> { 0.2, 0.4 }) {

		cout << endl << "Computing average shortest path for a random graph of "
				<< nodes_no << " and density " << density * 100 << "% ..."
				<< endl;
		graph G(nodes_no, density);

		//	G.print_graph();

		ShortestPath djisktra(G);

		vector<int> paths;

		for (int i = 1; i < nodes_no; ++i) {
			int lon = djisktra.path_size(0, i);
			if (lon >= 1) {
				paths.push_back(lon);
			}
		}

		cout << endl << "Average path length: "
				<< accumulate(paths.begin(), paths.end(), 0.0) / paths.size()
				<< endl << endl
				<< "------------------------------------------------------";

	}

	return 0;
}

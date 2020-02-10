#include<iostream>
#include <numeric>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(time(0));

	graph G("HW2/SampleTestData.txt");
	ShortestPath tree(G);

	auto minimum_tree = tree.MST();

	cout << minimum_tree.first << endl;


	minimum_tree.second.print_graph();

	cout << endl << ShortestPath(minimum_tree.second).is_connected() <<endl;

	return 0;
}

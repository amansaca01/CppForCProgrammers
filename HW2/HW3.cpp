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

	graph minimum_tree = tree.MST();

	G.print_graph();
	cout << endl;
	minimum_tree.print_graph();

	cout << endl << minimum_tree.tree_cost() <<endl;
	cout << endl << ShortestPath(minimum_tree).is_connected() <<endl;

	return 0;
}

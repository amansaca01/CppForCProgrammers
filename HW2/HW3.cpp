#include<iostream>
#include <numeric>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

	srand(time(0));

	graph G("HW2/SampleTestData.txt");

	cout << G.V() << endl;

	G.print_graph();

	return 0;
}

#include<iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

// Randomize seed
//	srand(time(NULL));
	srand(123);

// Generate a random graph
	int size = 5;
	float density = 0.8;
	int range = 10;
	graph G(size, density, range);

// Print the graph
	cout << "The connectivity matrix of the randomly generated graph of size "
			<< size << ", density " << density
			<< " and distances between 1 and " << range << " is:" << endl;
	G.print_graph();
	cout << endl;

// Computes the shortest paths of the n -1 paths: 1 to 2, ..., 1 to n.
	ShortestPath shortest_path(G);
	vector<int> path_lengths;

	for (int i = 1; i < size; ++i) {

		int length = shortest_path.path_size(0, i);
		path_lengths.push_back(length);
	}

// Print the vector of lengths
	cout
			<< "The lengths of the shortest paths from 1 to each of the nodes 2,..., "
			<< size << " are: " << endl;
	for (vector<int>::const_iterator i = path_lengths.begin();
			i != path_lengths.end(); ++i)
		cout << *i << ", ";
	cout << endl << endl;

// Computes the average shortest path of the 49 paths: 1 to 2, 1 to 3, 1 to 4, ..., 1 to 50.
	float average = accumulate(path_lengths.begin(), path_lengths.end(), 0.0)
			/ path_lengths.size();
	cout << "The average shortest path of the " << size - 1
			<< " paths: 1 to 2, ..., 1 to " << size << " is: " << average << "."
			<< endl;

	return 0;
}

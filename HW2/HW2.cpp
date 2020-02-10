#include <numeric>
//HW2
#include <iterator>

#include "graph.h"
#include "priority_queue.h"
#include "shortest_path.h"

using namespace std;

int main() {

    //HW2
    /*
    srand(123);

    vector<float> densit = {0.2, 0.4};
    for (auto const &dens : densit) {
        int nodes_no = 50;
        graph G(nodes_no, dens);

        // cout << "Adjacency matrix" << endl;
        // G.print_graph();
        // cout << endl;

        ShortestPath dijsktra(G);it

        cout << endl << "Dijsktras shortest path for " << nodes_no << " nodes and density " << dens << endl;

        vector<int> paths;istream_iterator<int> start(dataf),end;
        for (int i = 1; i < nodes_no; ++i) {
            int lon = dijsktra.path_size(0, i);
            if (lon >= 1) {
                paths.push_back(lon);
                // cout << i << " " << lon << endl;
            }
        }

        cout << "Average path length: " << accumulate(paths.begin(), paths.end(), 0.0) / paths.size() << endl;
    }
    */


    //HW3
    //string filename= "/home/diego.gozalo/Documents/curso-Cpp/cplusplus4c_homeworks_Homework3_SampleTestData_mst_data";
    //try first with small graph
    string filename= "/home/diego.gozalo/Documents/curso-Cpp/test_graph.txt";
    graph G(filename);

    cout << "Adjacency matrix" << endl;
    G.print_graph();
    cout << endl;





    return 0;
}

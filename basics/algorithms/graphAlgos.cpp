#include "graph.hpp"
#include <iostream>

using namespace std;

int main() {
	Graph graph(6);

	graph.addEdge(0, 1, 1);
	graph.addEdge(1, 2, 5);
	graph.addEdge(0, 2, 1);

	graph.addEdge(2, 3, 1);
	graph.addEdge(3, 4, 2);
	graph.addEdge(2, 4, -6);

	graph.addEdge(0, 5, 1);

	// Assume connected graphs
	cout << "BFS: ";
	graph.BFS(0);
	cout << endl;

	graph.resetVisited();

	cout << "DFS: ";
	graph.DFS(0);
	cout << endl;

	return 0;
}
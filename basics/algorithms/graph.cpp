#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(unsigned int V) : _V(V) {
	for (unsigned int i = 0; i < _V; i++) 
		_adj_list.push_back( map<unsigned int, int>() );

	_visited = new bool[_V];
	resetVisited(); // unmark all vertices
}

Graph::~Graph()
{
	delete [] _visited;
}

void Graph::resetVisited()
{
	for( unsigned int i = 0; i < _V; i++ ) _visited[i] = false;
}

void Graph::addEdge(unsigned int in, unsigned int out, int weight) 
{
	_adj_list[in][out] = weight;
}

void Graph::BFS(unsigned int start)
{
	_visited[start] = true; // mark starting vertex

	deque<unsigned int> queue;
	queue.push_front(start);

	while( !queue.empty() )
	{	
		unsigned int v = queue.front();
		cout << v << " ";
		queue.pop_front();

		for ( auto &it : _adj_list[v] ) // visit all neighbours first
		{
			unsigned int key = it.first;
			if ( !_visited[key] ) queue.push_back( key ); // visit these nodes later
			_visited[key] = true;
		}
	}
}

void Graph::DFS(unsigned int u)
{
	cout << u << " ";
	_visited[u] = true; // mark vertex as visited
	for ( auto &v : _adj_list[u] ) // visit all neighbours first
	{
		if ( !_visited[v.first] ) DFS(v.first);
	}
}
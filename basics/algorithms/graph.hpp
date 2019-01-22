#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <map>
#include <deque>

class Graph
{
	unsigned int _V;
    std::vector< std::map<unsigned int, int> > _adj_list;
    bool * _visited;

public:
    Graph() = delete;
    Graph(unsigned int V);
    ~Graph();

    void resetVisited();

    void addEdge(unsigned int in, unsigned int out, int weight);
    
    void BFS(unsigned int start);

    void DFS(unsigned int start);
};

#endif
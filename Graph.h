#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include "Edge.h"
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

// Abstract base class for graphs
class Graph {
protected:
    int vertices;           // Number of vertices
    bool directed;          // true if directed, false if undirected
    bool weighted;          // true if weighted, false if unweighted

public:
    Graph(int v, bool dir = false, bool w = false)
        : vertices(v), directed(dir), weighted(w) {}

    virtual ~Graph() {}

    // Basic operations
    virtual void addEdge(int src, int dest, int weight = 1) = 0;
    virtual void removeEdge(int src, int dest) = 0;
    virtual bool hasEdge(int src, int dest) const = 0;
    virtual int getWeight(int src, int dest) const = 0;

    // Graph algorithms
    virtual void BFS(int start) const = 0;
    virtual void DFS(int start) const = 0;
    virtual void DFSRecursive(int start) const = 0;

    // Utility functions
    virtual int getDegree(int vertex) const = 0;
    virtual int getInDegree(int vertex) const = 0;
    virtual int getOutDegree(int vertex) const = 0;
    virtual void printGraph() const = 0;

    // Getters
    int getVertices() const { return vertices; }
    bool isDirected() const { return directed; }
    bool isWeighted() const { return weighted; }

protected:
    // Helper for DFS recursive
    virtual void DFSUtil(int vertex, vector<bool>& visited) const = 0;
};


#endif // GRAPH_H_INCLUDED

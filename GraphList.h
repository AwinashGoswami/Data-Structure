#ifndef GRAPHLIST_H_INCLUDED
#define GRAPHLIST_H_INCLUDED

#include "Graph.h"
#include <list>
#include <vector>
#include <map>

// Structure for adjacency list node
struct AdjListNode {
    int dest;
    int weight;

    AdjListNode(int d, int w = 1) : dest(d), weight(w) {}
};

class GraphList : public Graph {
private:
    vector<list<AdjListNode>> adjList;  // Adjacency list

public:
    GraphList(int v, bool dir = false, bool w = false);
    ~GraphList();

    // Basic operations
    void addEdge(int src, int dest, int weight = 1) override;
    void removeEdge(int src, int dest) override;
    bool hasEdge(int src, int dest) const override;
    int getWeight(int src, int dest) const override;

    // Graph algorithms
    void BFS(int start) const override;
    void DFS(int start) const override;
    void DFSRecursive(int start) const override;

    // Utility functions
    int getDegree(int vertex) const override;
    int getInDegree(int vertex) const override;
    int getOutDegree(int vertex) const override;
    void printGraph() const override;

    // Additional list-specific algorithms
    vector<int> topologicalSort();                    // For DAG
    void Dijkstra(int source);                         // Single source shortest path
    vector<Edge> kruskalMST();                         // Minimum Spanning Tree
    bool hasCycle();                                    // Cycle detection

protected:
    void DFSUtil(int vertex, vector<bool>& visited) const override;

private:
    void DFSUtilRecursive(int vertex, vector<bool>& visited) const;
    bool hasCycleUtil(int vertex, vector<bool>& visited, vector<bool>& recStack);
};


#endif // GRAPHLIST_H_INCLUDED

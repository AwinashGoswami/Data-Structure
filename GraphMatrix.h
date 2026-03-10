#ifndef GRAPHMATRIX_H_INCLUDED
#define GRAPHMATRIX_H_INCLUDED

#include "Graph.h"
#include <vector>
#include <limits>

class GraphMatrix : public Graph {
private:
    vector<vector<int>> adjMatrix;  // Adjacency matrix
    static const int INF = numeric_limits<int>::max();

public:
    GraphMatrix(int v, bool dir = false, bool w = false);
    ~GraphMatrix();

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

    // Additional matrix-specific algorithms
    void FloydWarshall();                    // All pairs shortest path
    vector<vector<int>> transitiveClosure();  // Warshall's algorithm

protected:
    void DFSUtil(int vertex, vector<bool>& visited) const override;

private:
    void DFSUtilRecursive(int vertex, vector<bool>& visited) const;
};

#endif // GRAPHMATRIX_H_INCLUDED

#ifndef EDGE_H_INCLUDED
#define EDGE_H_INCLUDED

#include <iostream>
using namespace std;

// Structure to represent an edge in weighted graphs
struct Edge {
    int source;
    int destination;
    int weight;

    Edge(int src = 0, int dest = 0, int w = 1)
        : source(src), destination(dest), weight(w) {}

    // For sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }

    // For printing edge
    friend ostream& operator<<(ostream& os, const Edge& edge) {
        os << "(" << edge.source << " -> " << edge.destination
           << ", weight: " << edge.weight << ")";
        return os;
    }
};


#endif // EDGE_H_INCLUDED

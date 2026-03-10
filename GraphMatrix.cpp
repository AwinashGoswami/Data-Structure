#include "GraphMatrix.h"
#include <iostream>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>
using namespace std;

// Constructor
GraphMatrix::GraphMatrix(int v, bool dir, bool w)
    : Graph(v, dir, w) {

    // Initialize adjacency matrix with INF (no edge)
    adjMatrix.resize(vertices, vector<int>(vertices, INF));

    // Set diagonal to 0 (distance from vertex to itself)
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i][i] = 0;
    }

    cout << "Adjacency Matrix Graph created with " << vertices << " vertices" << endl;
}

// Destructor
GraphMatrix::~GraphMatrix() {
    cout << "Adjacency Matrix Graph destroyed" << endl;
}

// Add edge
void GraphMatrix::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        cout << "Error: Vertex out of range!" << endl;
        return;
    }

    adjMatrix[src][dest] = weighted ? weight : 1;

    if (!directed) {
        adjMatrix[dest][src] = weighted ? weight : 1;
    }

    cout << "Edge added: " << src << " -> " << dest;
    if (weighted) cout << " (weight: " << weight << ")";
    cout << endl;
}

// Remove edge
void GraphMatrix::removeEdge(int src, int dest) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        cout << "Error: Vertex out of range!" << endl;
        return;
    }

    adjMatrix[src][dest] = INF;

    if (!directed) {
        adjMatrix[dest][src] = INF;
    }

    cout << "Edge removed: " << src << " -> " << dest << endl;
}

// Check if edge exists
bool GraphMatrix::hasEdge(int src, int dest) const {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        return false;
    }

    return adjMatrix[src][dest] != INF;
}

// Get edge weight
int GraphMatrix::getWeight(int src, int dest) const {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        return INF;
    }

    return adjMatrix[src][dest];
}

// Breadth-First Search
void GraphMatrix::BFS(int start) const {
    if (start < 0 || start >= vertices) {
        cout << "Error: Start vertex out of range!" << endl;
        return;
    }

    cout << "BFS Traversal (starting from vertex " << start << "): ";

    vector<bool> visited(vertices, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        // Check all adjacent vertices
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] != INF && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// DFS Helper for iterative version
void GraphMatrix::DFSUtil(int vertex, vector<bool>& visited) const {
    stack<int> s;
    s.push(vertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            // Push all adjacent vertices in reverse order for natural DFS order
            for (int i = vertices - 1; i >= 0; i--) {
                if (adjMatrix[current][i] != INF && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
}

// Iterative DFS
void GraphMatrix::DFS(int start) const {
    if (start < 0 || start >= vertices) {
        cout << "Error: Start vertex out of range!" << endl;
        return;
    }

    cout << "DFS Traversal (Iterative, starting from vertex " << start << "): ";

    vector<bool> visited(vertices, false);
    DFSUtil(start, visited);

    // Handle disconnected components
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }
    cout << endl;
}

// DFS Helper for recursive version
void GraphMatrix::DFSUtilRecursive(int vertex, vector<bool>& visited) const {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] != INF && !visited[i]) {
            DFSUtilRecursive(i, visited);
        }
    }
}

// Recursive DFS
void GraphMatrix::DFSRecursive(int start) const {
    if (start < 0 || start >= vertices) {
        cout << "Error: Start vertex out of range!" << endl;
        return;
    }

    cout << "DFS Traversal (Recursive, starting from vertex " << start << "): ";

    vector<bool> visited(vertices, false);
    DFSUtilRecursive(start, visited);

    // Handle disconnected components
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFSUtilRecursive(i, visited);
        }
    }
    cout << endl;
}

// Get degree of vertex (for undirected graph)
int GraphMatrix::getDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices) {
        return -1;
    }

    int degree = 0;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] != INF && i != vertex) {
            degree++;
        }
    }

    return degree;
}

// Get in-degree (for directed graph)
int GraphMatrix::getInDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices || !directed) {
        return -1;
    }

    int inDegree = 0;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[i][vertex] != INF && i != vertex) {
            inDegree++;
        }
    }

    return inDegree;
}

// Get out-degree (for directed graph)
int GraphMatrix::getOutDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices || !directed) {
        return -1;
    }

    int outDegree = 0;
    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] != INF && i != vertex) {
            outDegree++;
        }
    }

    return outDegree;
}

// Print graph
void GraphMatrix::printGraph() const {
    cout << "\nAdjacency Matrix:" << endl;
    cout << "    ";
    for (int i = 0; i < vertices; i++) {
        cout << setw(4) << i;
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << setw(2) << i << ": ";
        for (int j = 0; j < vertices; j++) {
            if (adjMatrix[i][j] == INF) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << adjMatrix[i][j];
            }
        }
        cout << endl;
    }

    cout << "\nGraph Properties:" << endl;
    cout << "  Directed: " << (directed ? "Yes" : "No") << endl;
    cout << "  Weighted: " << (weighted ? "Yes" : "No") << endl;
    cout << "  Vertices: " << vertices << endl;

    if (!directed) {
        cout << "\nDegrees:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "  Vertex " << i << ": degree = " << getDegree(i) << endl;
        }
    } else {
        cout << "\nIn/Out Degrees:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "  Vertex " << i << ": in-degree = " << getInDegree(i)
                 << ", out-degree = " << getOutDegree(i) << endl;
        }
    }
}

// Floyd-Warshall Algorithm (All Pairs Shortest Path)
void GraphMatrix::FloydWarshall() {
    cout << "\nFloyd-Warshall Algorithm (All Pairs Shortest Path):" << endl;

    vector<vector<int>> dist = adjMatrix;

    // Floyd-Warshall core algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print result
    cout << "Shortest distances between all pairs:" << endl;
    cout << "    ";
    for (int i = 0; i < vertices; i++) {
        cout << setw(4) << i;
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << setw(2) << i << ": ";
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << dist[i][j];
            }
        }
        cout << endl;
    }
}

// Warshall's Algorithm (Transitive Closure)
vector<vector<int>> GraphMatrix::transitiveClosure() {
    cout << "\nWarshall's Algorithm (Transitive Closure):" << endl;

    vector<vector<int>> closure(vertices, vector<int>(vertices, 0));

    // Initialize closure matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            closure[i][j] = (adjMatrix[i][j] != INF) ? 1 : 0;
        }
    }

    // Warshall's algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
            }
        }
    }

    // Print result
    cout << "Transitive Closure (reachability matrix):" << endl;
    cout << "    ";
    for (int i = 0; i < vertices; i++) {
        cout << setw(3) << i;
    }
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        cout << setw(2) << i << ": ";
        for (int j = 0; j < vertices; j++) {
            cout << setw(3) << closure[i][j];
        }
        cout << endl;
    }

    return closure;
}

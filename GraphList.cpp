#include "GraphList.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <limits>
using namespace std;

// Constructor
GraphList::GraphList(int v, bool dir, bool w)
    : Graph(v, dir, w) {

    adjList.resize(vertices);
    cout << "Adjacency List Graph created with " << vertices << " vertices" << endl;
}

// Destructor
GraphList::~GraphList() {
    cout << "Adjacency List Graph destroyed" << endl;
}

// Add edge
void GraphList::addEdge(int src, int dest, int weight) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        cout << "Error: Vertex out of range!" << endl;
        return;
    }

    // Add edge from src to dest
    adjList[src].push_back(AdjListNode(dest, weighted ? weight : 1));

    if (!directed) {
        // Add edge from dest to src for undirected graph
        adjList[dest].push_back(AdjListNode(src, weighted ? weight : 1));
    }

    cout << "Edge added: " << src << " -> " << dest;
    if (weighted) cout << " (weight: " << weight << ")";
    cout << endl;
}

// Remove edge
void GraphList::removeEdge(int src, int dest) {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        cout << "Error: Vertex out of range!" << endl;
        return;
    }

    // Remove edge from src to dest
    auto& list = adjList[src];
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->dest == dest) {
            list.erase(it);
            break;
        }
    }

    if (!directed) {
        // Remove edge from dest to src for undirected graph
        auto& list2 = adjList[dest];
        for (auto it = list2.begin(); it != list2.end(); ++it) {
            if (it->dest == src) {
                list2.erase(it);
                break;
            }
        }
    }

    cout << "Edge removed: " << src << " -> " << dest << endl;
}

// Check if edge exists
bool GraphList::hasEdge(int src, int dest) const {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        return false;
    }

    for (const auto& node : adjList[src]) {
        if (node.dest == dest) {
            return true;
        }
    }

    return false;
}

// Get edge weight
int GraphList::getWeight(int src, int dest) const {
    if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) {
        return -1;
    }

    for (const auto& node : adjList[src]) {
        if (node.dest == dest) {
            return node.weight;
        }
    }

    return -1;  // Edge doesn't exist
}

// Breadth-First Search
void GraphList::BFS(int start) const {
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

        // Visit all adjacent vertices
        for (const auto& node : adjList[current]) {
            if (!visited[node.dest]) {
                visited[node.dest] = true;
                q.push(node.dest);
            }
        }
    }
    cout << endl;
}

// DFS Helper for iterative version
void GraphList::DFSUtil(int vertex, vector<bool>& visited) const {
    stack<int> s;
    s.push(vertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            // Push all adjacent vertices to stack
            for (const auto& node : adjList[current]) {
                if (!visited[node.dest]) {
                    s.push(node.dest);
                }
            }
        }
    }
}

// Iterative DFS
void GraphList::DFS(int start) const {
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
void GraphList::DFSUtilRecursive(int vertex, vector<bool>& visited) const {
    visited[vertex] = true;
    cout << vertex << " ";

    for (const auto& node : adjList[vertex]) {
        if (!visited[node.dest]) {
            DFSUtilRecursive(node.dest, visited);
        }
    }
}

// Recursive DFS
void GraphList::DFSRecursive(int start) const {
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
int GraphList::getDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices) {
        return -1;
    }

    if (!directed) {
        return adjList[vertex].size();
    }

    // For directed graph, degree = in-degree + out-degree
    return getInDegree(vertex) + getOutDegree(vertex);
}

// Get in-degree (for directed graph)
int GraphList::getInDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices || !directed) {
        return -1;
    }

    int inDegree = 0;
    for (int i = 0; i < vertices; i++) {
        for (const auto& node : adjList[i]) {
            if (node.dest == vertex) {
                inDegree++;
            }
        }
    }

    return inDegree;
}

// Get out-degree (for directed graph)
int GraphList::getOutDegree(int vertex) const {
    if (vertex < 0 || vertex >= vertices || !directed) {
        return -1;
    }

    return adjList[vertex].size();
}

// Print graph
void GraphList::printGraph() const {
    cout << "\nAdjacency List:" << endl;

    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": ";
        if (adjList[i].empty()) {
            cout << "No outgoing edges";
        } else {
            for (const auto& node : adjList[i]) {
                if (weighted) {
                    cout << " -> (" << node.dest << ", weight:" << node.weight << ")";
                } else {
                    cout << " -> " << node.dest;
                }
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

// Topological Sort (for Directed Acyclic Graph)
vector<int> GraphList::topologicalSort() {
    vector<int> result;

    if (!directed) {
        cout << "Topological sort is only for directed graphs!" << endl;
        return result;
    }

    cout << "\nTopological Sort:" << endl;

    vector<int> inDegree(vertices, 0);

    // Calculate in-degree for each vertex
    for (int i = 0; i < vertices; i++) {
        for (const auto& node : adjList[i]) {
            inDegree[node.dest]++;
        }
    }

    // Queue for vertices with in-degree 0
    queue<int> q;
    for (int i = 0; i < vertices; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        result.push_back(current);
        count++;

        // Reduce in-degree of adjacent vertices
        for (const auto& node : adjList[current]) {
            inDegree[node.dest]--;
            if (inDegree[node.dest] == 0) {
                q.push(node.dest);
            }
        }
    }

    // Check for cycle
    if (count != vertices) {
        cout << "Graph has a cycle! Topological sort not possible." << endl;
        result.clear();
    } else {
        cout << "Topological order: ";
        for (int v : result) {
            cout << v << " ";
        }
        cout << endl;
    }

    return result;
}

// Dijkstra's Algorithm (Single Source Shortest Path)
void GraphList::Dijkstra(int source) {
    if (!weighted) {
        cout << "Dijkstra algorithm requires weighted graph!" << endl;
        return;
    }

    cout << "\nDijkstra's Algorithm (Shortest paths from vertex " << source << "):" << endl;

    const int INF = numeric_limits<int>::max();
    vector<int> dist(vertices, INF);
    vector<int> parent(vertices, -1);
    vector<bool> visited(vertices, false);

    dist[source] = 0;

    // Min-heap priority queue: (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (visited[current]) continue;
        visited[current] = true;

        // Relax all adjacent edges
        for (const auto& node : adjList[current]) {
            int next = node.dest;
            int weight = node.weight;

            if (!visited[next] && dist[current] != INF &&
                dist[current] + weight < dist[next]) {
                dist[next] = dist[current] + weight;
                parent[next] = current;
                pq.push({dist[next], next});
            }
        }
    }

    // Print results
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            cout << "  To vertex " << i << ": unreachable" << endl;
        } else {
            cout << "  To vertex " << i << ": " << dist[i];

            // Print path
            cout << " (path: ";
            vector<int> path;
            for (int v = i; v != -1; v = parent[v]) {
                path.push_back(v);
            }
            for (int j = path.size() - 1; j >= 0; j--) {
                cout << path[j];
                if (j > 0) cout << " -> ";
            }
            cout << ")";
            cout << endl;
        }
    }
}

// Kruskal's Algorithm (Minimum Spanning Tree)
vector<Edge> GraphList::kruskalMST() {
    vector<Edge> mst;

    if (directed) {
        cout << "Kruskal's algorithm is for undirected graphs!" << endl;
        return mst;
    }

    cout << "\nKruskal's Algorithm (Minimum Spanning Tree):" << endl;

    // Collect all edges
    vector<Edge> edges;
    set<pair<int, int>> added;  // To avoid duplicate edges in undirected graph

    for (int i = 0; i < vertices; i++) {
        for (const auto& node : adjList[i]) {
            int u = i;
            int v = node.dest;

            // For undirected, add each edge only once
            if (added.count({min(u, v), max(u, v)}) == 0) {
                edges.push_back(Edge(u, v, node.weight));
                added.insert({min(u, v), max(u, v)});
            }
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Disjoint Set Union (Union-Find) for cycle detection
    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    // Find with path compression
    function<int(int)> find = [&](int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    };

    // Union by rank
    auto unionSets = [&](int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    };

    // Kruskal's algorithm
    int mstWeight = 0;
    for (const auto& edge : edges) {
        if (unionSets(edge.source, edge.destination)) {
            mst.push_back(edge);
            mstWeight += edge.weight;

            cout << "Added edge: " << edge << endl;

            if (mst.size() == vertices - 1) break;
        }
    }

    cout << "Total MST weight: " << mstWeight << endl;
    return mst;
}

// Helper for cycle detection in directed graph
bool GraphList::hasCycleUtil(int vertex, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        recStack[vertex] = true;

        for (const auto& node : adjList[vertex]) {
            if (!visited[node.dest] && hasCycleUtil(node.dest, visited, recStack)) {
                return true;
            } else if (recStack[node.dest]) {
                return true;
            }
        }
    }

    recStack[vertex] = false;
    return false;
}

// Cycle detection
bool GraphList::hasCycle() {
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (hasCycleUtil(i, visited, recStack)) {
            cout << "Cycle detected in the graph!" << endl;
            return true;
        }
    }

    cout << "No cycle detected in the graph." << endl;
    return false;
}

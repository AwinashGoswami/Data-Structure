#include "GraphMatrix.h"
#include "GraphList.h"
#include <iostream>
using namespace std;

void demonstrateGraphMatrix() {
    cout << "\n==========================================" << endl;
    cout << "     ADJACENCY MATRIX GRAPH DEMO" << endl;
    cout << "==========================================\n" << endl;

    // Create an undirected unweighted graph
    cout << "--- Creating Undirected Unweighted Graph ---" << endl;
    GraphMatrix g1(5, false, false);

    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);

    g1.printGraph();

    cout << "\n--- Traversals ---" << endl;
    g1.BFS(0);
    g1.DFS(0);
    g1.DFSRecursive(0);

    cout << "\n--- Edge Operations ---" << endl;
    cout << "Has edge (1,3): " << (g1.hasEdge(1, 3) ? "Yes" : "No") << endl;
    cout << "Has edge (0,2): " << (g1.hasEdge(0, 2) ? "Yes" : "No") << endl;

    g1.removeEdge(1, 3);
    cout << "After removing edge (1,3):" << endl;
    cout << "Has edge (1,3): " << (g1.hasEdge(1, 3) ? "Yes" : "No") << endl;

    cout << "\n--- Creating Weighted Directed Graph ---" << endl;
    GraphMatrix g2(4, true, true);

    g2.addEdge(0, 1, 5);
    g2.addEdge(0, 2, 3);
    g2.addEdge(1, 3, 2);
    g2.addEdge(2, 1, 1);
    g2.addEdge(2, 3, 4);
    g2.addEdge(3, 0, 2);

    g2.printGraph();

    cout << "\n--- Floyd-Warshall Algorithm ---" << endl;
    g2.FloydWarshall();

    cout << "\n--- Transitive Closure ---" << endl;
    g2.transitiveClosure();
}

void demonstrateGraphList() {
    cout << "\n==========================================" << endl;
    cout << "     ADJACENCY LIST GRAPH DEMO" << endl;
    cout << "==========================================\n" << endl;

    // Create a directed weighted graph
    cout << "--- Creating Directed Weighted Graph ---" << endl;
    GraphList g1(6, true, true);

    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 2, 3);
    g1.addEdge(1, 2, 1);
    g1.addEdge(1, 3, 2);
    g1.addEdge(2, 3, 4);
    g1.addEdge(2, 4, 3);
    g1.addEdge(3, 4, 2);
    g1.addEdge(3, 5, 1);
    g1.addEdge(4, 5, 5);

    g1.printGraph();

    cout << "\n--- Traversals ---" << endl;
    g1.BFS(0);
    g1.DFS(0);
    g1.DFSRecursive(0);

    cout << "\n--- Cycle Detection ---" << endl;
    g1.hasCycle();

    cout << "\n--- Topological Sort (DAG) ---" << endl;
    g1.topologicalSort();

    cout << "\n--- Dijkstra's Algorithm ---" << endl;
    g1.Dijkstra(0);

    cout << "\n--- Creating Undirected Weighted Graph for MST ---" << endl;
    GraphList g2(5, false, true);

    g2.addEdge(0, 1, 2);
    g2.addEdge(0, 3, 6);
    g2.addEdge(1, 2, 3);
    g2.addEdge(1, 3, 8);
    g2.addEdge(1, 4, 5);
    g2.addEdge(2, 4, 7);
    g2.addEdge(3, 4, 9);

    g2.printGraph();

    cout << "\n--- Kruskal's MST Algorithm ---" << endl;
    g2.kruskalMST();
}

void demonstrateGraphWithCycle() {
    cout << "\n==========================================" << endl;
    cout << "        GRAPH WITH CYCLE DEMO" << endl;
    cout << "==========================================\n" << endl;

    // Create a graph with a cycle
    GraphList g(4, true, false);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);  // Creates a cycle
    g.addEdge(2, 3);

    g.printGraph();

    cout << "\n--- Cycle Detection ---" << endl;
    g.hasCycle();

    cout << "\n--- Topological Sort (should fail) ---" << endl;
    g.topologicalSort();
}

void compareImplementations() {
    cout << "\n==========================================" << endl;
    cout << "   COMPARISON: MATRIX vs LIST" << endl;
    cout << "==========================================\n" << endl;

    cout << "ADJACENCY MATRIX:" << endl;
    cout << "✓ O(1) edge lookup" << endl;
    cout << "✓ Good for dense graphs" << endl;
    cout << "✓ Simple to implement" << endl;
    cout << "✗ O(V²) memory" << endl;
    cout << "✗ O(V) to find neighbors" << endl;
    cout << "✗ Wastes space for sparse graphs" << endl;
    cout << endl;

    cout << "ADJACENCY LIST:" << endl;
    cout << "✓ O(V + E) memory (efficient for sparse graphs)" << endl;
    cout << "✓ O(degree) to find neighbors (faster traversal)" << endl;
    cout << "✓ Better for most graph algorithms" << endl;
    cout << "✗ O(degree) edge lookup" << endl;
    cout << "✗ More complex implementation" << endl;
    cout << "✗ Slightly more overhead per edge" << endl;
    cout << endl;

    cout << "When to use each:" << endl;
    cout << "• Use MATRIX for dense graphs (E ≈ V²)" << endl;
    cout << "• Use MATRIX when you need frequent edge lookups" << endl;
    cout << "• Use LIST for sparse graphs (E << V²)" << endl;
    cout << "• Use LIST for traversals and most algorithms" << endl;
}

int main() {
    cout << "==============================================" << endl;
    cout << "           GRAPH DATA STRUCTURES" << endl;
    cout << "==============================================" << endl;

    demonstrateGraphMatrix();
    demonstrateGraphList();
    demonstrateGraphWithCycle();
    compareImplementations();

    cout << "\n==============================================" << endl;
    cout << "        Graph Demonstrations Complete!" << endl;
    cout << "==============================================" << endl;

    return 0;
}

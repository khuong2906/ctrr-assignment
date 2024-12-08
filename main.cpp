#include <iostream>
#include "bellman.h"   // Include the Bellman-Ford header
#include "TSP_H.H"  // Include the TSP header
#include "tsp.cpp"
#include "bellman.cpp"
using namespace std;

int main() {
    // Define the graph as a 30x30 adjacency matrix
    int graph[30][30] = {0};

    // Example for Bellman-Ford
    int vertices = 5; // Number of vertices (A, B, C, D, E)
    char startVertex = 'A';
    char endVertex = 'E';

    // Define edges with weights for Bellman-Ford example
    graph[0][1] = 6;  // A -> B
    graph[0][3] = 7;  // A -> D
    graph[1][2] = 5;  // B -> C
    graph[1][3] = 8;  // B -> D
    graph[1][4] = -4; // B -> E
    graph[2][1] = -2; // C -> B
    graph[3][2] = -3; // D -> C
    graph[3][4] = 9;  // D -> E
    graph[4][0] = 2;  // E -> A
    graph[4][2] = 7;  // E -> C

    // Test Bellman-Ford
    string bf_result = BF_Path(graph, vertices, startVertex, endVertex);
    if (bf_result == "No path found") {
        cout << "No path exists from " << startVertex << " to " << endVertex << " using Bellman-Ford." << endl;
    } else {
        cout << "Shortest path from " << startVertex << " to " << endVertex << " (Bellman-Ford): " << bf_result << endl;
    }

    // Example for TSP
    int tsp_graph[30][30] = {0}; // Reset graph for TSP
    vertices = 4; // Number of vertices (A, B, C, D)

    // Define edges with weights for TSP example
    tsp_graph[0][1] = 10; tsp_graph[1][0] = 10; // A <-> B
    tsp_graph[0][2] = 15; tsp_graph[2][0] = 15; // A <-> C
    tsp_graph[0][3] = 20; tsp_graph[3][0] = 20; // A <-> D
    tsp_graph[1][2] = 35; tsp_graph[2][1] = 35; // B <-> C
    tsp_graph[1][3] = 25; tsp_graph[3][1] = 25; // B <-> D
    tsp_graph[2][3] = 30; tsp_graph[3][2] = 30; // C <-> D

    // Test TSP
    string tsp_result = Traveling(tsp_graph, vertices, startVertex);
    if (tsp_result == "No solution") {
        cout << "No solution exists for the Traveling Salesman Problem." << endl;
    } else {
        cout << "Shortest Hamiltonian cycle (TSP): " << tsp_result << endl;
    }

    return 0;
}

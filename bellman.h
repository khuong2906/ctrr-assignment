#ifndef bellman_h
#define bellman_h

#include <string>

using namespace std;

// Function to perform the Bellman-Ford algorithm to calculate shortest paths
void BF(int graph[30][30], int vertices, char startVertex, int valueArray[30], int prevArray[30]);

// Function to find the shortest path from startVertex to endVertex using Bellman-Ford
string BF_Path(int graph[30][30], int vertices, char startVertex, char endVertex);

#endif // BF_H

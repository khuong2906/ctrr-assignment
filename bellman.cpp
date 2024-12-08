#include <iostream>
// #define INF 1000000 // or any large value representing infinity
#include <climits>
#include "bellman.h"
using namespace std; 
void BF(int graph[30][30], int vertices, char startVertex, int valueArray[30], int prevArray[30]) {
    int start = startVertex - 'A'; 
    valueArray[start] = 0;
    bool isFirstStep = true;

    for (int i = 0; i < vertices; ++i) {
        if (valueArray[i] != -1&& i!=start ) {
            isFirstStep = false;
            break;
        }
    }

     if (isFirstStep) {
        for (int v = 0; v < vertices; ++v) {
            if (graph[start][v] > 0) {
                    valueArray[v] = valueArray[start] + graph[start][v];
                    prevArray[v] = start;
            }
        }   
        return;
    }
    
    int tempArray[30];
    for (int j = 0; j < vertices; ++j) {
        tempArray[j] = valueArray[j];
    }
        
    for (int i = 0; i < vertices - 1; ++i) {
        for (int u = 0; u < vertices; ++u) {
            if (valueArray[u] == -1) continue;
            for (int v = 0; v < vertices; ++v) {
                if (graph[u][v] > 0) {
                    if (tempArray[u] + graph[u][v] < valueArray[v] || valueArray[v]==-1) {
                        valueArray[v] = tempArray[u] + graph[u][v];
                        prevArray[v] = u;
                    }
                }
            }
        }
    }
    
}


string BF_Path(int graph[30][30], int vertices, char startVertex, char endVertex) {
      int BFValue[30];
      int BFPrev[30];
      int index[30];
    int current = endVertex - 'A';
    int pathLength = 0;
    for (int i = 0; i < vertices; i++) {
        BFValue[i] = 999;
        BFPrev[i] = -1;
    }
    for(int i=0;i<vertices -1 ;i++){
        BF(graph, vertices, startVertex, BFValue, BFPrev);
    }
    
    while (current != (startVertex - 'A')) {
        if (current == -1 ) return "No path found";
        index[pathLength] = current;
        current = BFPrev[current];
        pathLength+=1;
    }
    index[pathLength] = startVertex - 'A'; 

    string result = "";
    for (int i = pathLength; i >= 0; --i) {
        result += (index[i] + 'A');
        result += " ";
    }

    return result;
    
}

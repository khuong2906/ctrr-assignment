#include <iostream>
// #define INF 1000000 // or any large value representing infinity
using namespace std;

void BF(int graph[30][30],int V,char u, int BFValue[], int BFPrev[]   ) //u is source vertex 
{
    int start= u -'A';

    BFValue[start] = 0;

    for(int k=0; k<=V-1; k++) { // k is the number of iterations
        for(int v=0; v<V; v++) { // v is the vertex being considered
            for(int s=0; s<V; s++) { // s is the source vertex
                if((graph[s][v] != 0 && BFValue[v] > BFValue[s] + graph[s][v]) || (BFValue[v]=-1 && graph[s][v] != 0)   ) {
                    BFValue[v ] = BFValue[s] + graph[s][v];
                    BFPrev[v] = s;
                }
            }
        }
    }
}

int main() {
    int graph[30][30] = {
        {0, 6, 0, 2, 7},
        {6, 0, 2, 4, 8},
        {0, 2, 0, 7, 0},
        {2, 4, 7, 0, 9},
        {7, 8, 0, 9, 0}
    };
    char u = 'A';
    int V = 5;               // Số lượng đỉnh        // Đỉnh nguồn
    int BFValue[30], BFPrev[30];
for(int i=0;i<V;i++){
BFValue[i]=-1;
BFPrev[i]=-1;
}
    BF(graph, V, u, BFValue, BFPrev);

    std::cout << "Khoảng cách từ đỉnh nguồn:" << std::endl;
    for (int i = 0; i < V; i++) {
        cout<<BFValue[i]<<" ";
    }

    return 0;
}
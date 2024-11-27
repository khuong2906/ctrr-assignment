#include <iostream>
#define INF 1000000 // or any large value representing infinity
using namespace std;
void BF(int BFValue[], int BFPrev[], int V, int u, int graph[30][30] ) //u is source vertex 
{
//     for(int i=0;i<V;i++)
// {
//     BFValue[i]=INF;
//     BFPrev[i]=-1;
// }
BFValue[u]=0;
for(int k=0;k<V-2;k++){ //k la so vong lap 
    for(int v=0;v<V;v++){ //v la dinh dang xet 
    if(v!=u){
        for(int s=1; s<=V; s++ ){
            if((graph[s][v]!=INF)           &&(BFValue[s]!=INF)          &&(BFValue[v]>BFValue[s]+graph[s][v])){
                                BFValue[v]=BFValue[s]+graph[s][v];
                             BFPrev[v]=s;
            }
        }
    }
}
}
}
int main() {
    int graph[30][30] = {
        {0, 6, 0, 0, 7},
        {0, 0, 5, -4, 8},
        {0, -2, 0, 0, 0},
        {2, 0, 7, 0, 0},
        {0, 0, -3, 9, 0}
    };
    int u = 0;
    int V = 5;               // Số lượng đỉnh
    int source = 0;          // Đỉnh nguồn
    int BFValue[30], BFPrev[30];

    BF(BFValue, BFPrev, V, source, graph);

    std::cout << "Khoảng cách từ đỉnh nguồn:" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cout << "Đỉnh " << i << ": " << (BFValue[i] == INF ? "INF" : std::to_string(BFValue[i])) << std::endl;
    }

    return 0;
}
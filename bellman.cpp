#include <iostream>
// #define INF 1000000 // or any large value representing infinity
using namespace std;

void BF(int graph[30][30],int V,char u, int BFValue[], int BFPrev[]   ) //u is source vertex 
{
    int start= u -'A';
    bool isFirstTime=true;
         for(int i = 0 ; i<V ; i++){
               if(BFValue[i] != -1&& BFValue[i]!=start) 
               isFirstTime= false; 
           }    
          
    if(isFirstTime){
        for (int v = 0; v < V; ++v) {
            // Nếu có cạnh từ u -> v
            if (graph[start][v] > 0) {
                BFValue[v] = BFValue[u] + graph[u][v];
                BFPrev[v] = u;  // Đánh dấu là đã có cập nhật
            }
        }
    }
    BFValue[start] = 0; // k is the number of iterations
       for (int u = 0; u <V; ++u) {
            for (int v = 0; v < V; ++v) {
                // Nếu có cạnh từ u -> v
                if (graph[u][v] > 0) {
                    // Nếu v chưa được truy cập hoặc khoảng cách qua u nhỏ hơn khoảng cách hiện tại của v
                    if ((BFValue[v] == -1 && BFValue[u] >= 0) || 
                        (BFValue[u] + graph[u][v] < BFValue[v] && BFValue[u] >= 0)) {
                        BFValue[v] = BFValue[u] + graph[u][v];
                        BFPrev[v] = u;  // Đánh dấu là đã có cập nhật
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
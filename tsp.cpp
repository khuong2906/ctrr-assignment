#include <iostream>
using namespace std; 
int n=12;
int ans=10000;
int traveling(int G[20][20],int n,char startLetter){
    int start= startLetter-'A';
    int visited[100];
    int X[n+1];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[start]=1;
    X[0]=start;
    Try(1,visited,X,G,start);
    return ans;
}

void visited(){
    
}


void Try(int i, int visited[100],int X[],int G[20][20], int start){ 
    int d=0;
    for(int j=0 ; j<=n ; j++){
        if(visited[j]==0&& G[i][j]!=0){
            visited[j]==1;
            X[i]=j; 
            d+= G[i][j];
        } 
        if(i==n&&G[X[i]][start]!=0){
            if(d+G[X[i]][start]<ans){
                ans = d+G[X[i]][start];
            }
        } else Try(i+1,visited,X,G,start);
        visited[j]=0;
        d -= G[X[i-1]][X[i]];
    }
}

int pathlength(int G[30][30], int n, string path) {
    int cost = 0;
    for (int i = 0; i < path.length() - 1; i++) {
        int from = path[i] - 'A';
        int to = path[i + 1] - 'A';
        cost += G[from][to];
    }
    return cost;
}

int main(){
    int n=5; 
    int G[20][20] = {
        {0, 6, 0, 2, 7},
        {6, 0, 2, 4, 8},
        {0, 2, 0, 7, 0},
        {2, 4, 7, 0, 9},
        {7, 8, 0, 9, 0}
    };
    cout<< traveling(G,n,'C');

}
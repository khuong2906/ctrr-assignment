#include <iostream>
#include "main.cpp"
#include <string>
#include <vector>
using namespace std;

int ans = 100000;  
vector<int> best_path(30);
vector<vector<int>> dp; 

// Branch and Bound
void Try(int i, int mask, vector<int>& X, int G[30][30], int start, int n, int d, bool size ) {
    if (i == n) {
        if (G[X[i - 1]][start] != 0) {
            int total_cost = d + G[X[i - 1]][start];
            if (total_cost < ans) {
                ans = total_cost;
                best_path = X;
            }
        }
        return;
    }
    if(size){
        int lb = d;
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                int min_edge = 100000;
                // Find the minimum edge for each unvisited node
                for (int k = 0; k < n; k++) {
                    if ((mask & (1 << k)) == 0 && G[j][k] != 0) {
                        min_edge = min(min_edge, G[j][k]);
                    }
                }
                lb += min_edge;
            }
        }
    
        // Pruning: If the lower bound exceeds current best cost, return
        if (lb >= ans) return;
    }

    // Branching: Explore all possible next cities
    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) == 0 && G[X[i - 1]][j] != 0) { 
            // Pruning: If adding this edge exceeds the best cost, skip
            if (d + G[X[i - 1]][j] >= ans) continue;

            if (dp[mask][j] != -1 && dp[mask][j] <= d + G[X[i - 1]][j]) continue;

            int new_mask = mask | (1 << j);
            X[i] = j;
            dp[mask][j] = d + G[X[i - 1]][j]; 
            Try(i + 1, new_mask, X, G, start, n, d + G[X[i - 1]][j],size );
        }
    }
}

string Traveling(int G[30][30], int n, char startLetter) {
    int start = startLetter - 'A';
    vector<int> X(30);

    ans = 100000;
    X[0] = start;

    dp = vector<vector<int>>(1 << n, vector<int>(n, -1));
    if(n<20) Try(1, 1 << start, X, G, start, n, 0,0 );
    else Try(1, 1 << start, X, G, start, n, 0,1  );

    if (ans == 100000) return "No solution";

    string result = "";
    for (int i = 0; i < n; i++) {
        result += (best_path[i] + 'A');
        result += " ";
    }
    result += startLetter;  
    return result;
}
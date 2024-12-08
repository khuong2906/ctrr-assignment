#ifndef TSP_H
#define TSP_H

#include <string>
#include <vector>

using namespace std;

// Function to solve the Traveling Salesman Problem using Branch and Bound
void Try(int i, int mask, vector<int>& X, int G[30][30], int start, int n, int d);

// Wrapper function to find the shortest Hamiltonian cycle using the TSP algorithm
string Traveling(int G[30][30], int n, char startLetter);

#endif // TSP_H

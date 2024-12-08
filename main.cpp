#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX

using namespace std;

// Function prototypes
string Traveling(int G[30][30], int n, char startLetter);

int main() {
    // Define the graph as a 30x30 adjacency matrix
    int G[30][30] = {0}; 

    // Example graph
    int n = 16; // Number of nodes (for example A, B, C, D)
    char startLetter = 'A';

    // Fill the graph (adjacency matrix)
    // For simplicity, we manually define the costs between nodes
int tempG[30][30] = {
    {0, 221, 220, 170, 113, 296, 77, 78, 155, 287, 383, 0, 183, 386, 411, 329},
    {498, 0, 200, 65, 165, 0, 0, 117, 274, 327, 420, 8, 49, 396, 75, 159},
    {171, 498, 0, 447, 4, 219, 19, 26, 184, 167, 103, 114, 175, 391, 349, 358},
    {129, 113, 187, 0, 0, 479, 165, 104, 0, 496, 282, 379, 176, 54, 239, 225},
    {0, 0, 0, 450, 0, 314, 384, 122, 165, 183, 0, 126, 236, 0, 202, 0},
    {0, 0, 0, 152, 273, 0, 369, 108, 387, 396, 351, 89, 254, 480, 202, 294},
    {311, 367, 0, 398, 307, 1, 0, 129, 483, 0, 56, 221, 0, 208, 358, 35},
    {444, 0, 0, 0, 480, 52, 127, 0, 0, 458, 289, 329, 111, 62, 0, 51},
    {71, 301, 447, 0, 422, 390, 54, 0, 0, 254, 444, 348, 65, 163, 98, 0},
    {372, 165, 80, 356, 73, 0, 301, 416, 431, 0, 336, 361, 412, 241, 488, 222},
    {30, 170, 0, 185, 444, 73, 256, 97, 372, 178, 0, 340, 426, 432, 284, 274},
    {0, 497, 448, 225, 0, 222, 465, 0, 0, 305, 0, 0, 430, 38, 106, 346},
    {469, 294, 0, 59, 233, 35, 400, 456, 417, 70, 493, 0, 0, 0, 361, 495},
    {0, 250, 311, 367, 428, 151, 0, 146, 213, 287, 272, 62, 235, 0, 497, 284},
    {52, 302, 214, 90, 260, 413, 412, 0, 55, 0, 0, 472, 497, 442, 0, 372},
    {0, 305, 360, 294, 299, 73, 289, 401, 384, 9, 181, 387, 7, 394, 175, 0}
};
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
G[i][j]=tempG[i][j];
}
}
    // Call the Traveling function
    string result = Traveling(G, n, startLetter);

    // Print the result
    if (result == "No solution") {
        cout << "No solution exists for the given graph." << endl;
    } else {
        cout << "Shortest path: " << result << endl;
    }

    return 0;
}

  
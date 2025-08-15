#include <iostream>
using namespace std;

vector<vector<int>> edgeListToAdjMatrix(vector<pair<int,int>> &edges, int n) {
    // Create n x n matrix initialized with 0
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;           // For undirected graph: also add adjMatrix[v][u] = 1;
    }
    return adjMatrix;
}

int main() {
    // Example edge list
    vector<pair<int,int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3;  // number of vertices

    vector<vector<int>> adjMatrix = edgeListToAdjMatrix(edges, n);

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

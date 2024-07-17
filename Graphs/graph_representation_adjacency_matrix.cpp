#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int> &arr) {
    for (auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
}
void printArray_2D(vector<vector<int>> &arr) {
    for (auto it : arr) {
        for (auto it2 : it) {
            cout << it2 << " ";
        }
        cout << endl;
    }
}

/*
Time complexity: O(V * V)
Space complexity: O(V * V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

/*
Graphs representation:
1). Adjacency matrix
2). Adjacency list
*/

void printGraph(vector<vector<bool>> &graph) {
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Take Input here if needed
    */

    int vertex, edges;
    cin >> vertex >> edges;

    /*
    1. Adjacency matrix
    Undirected unweighted graph
    */
    vector<vector<bool>> adj_matrix(vertex, vector<bool>(vertex, 0));
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    printGraph(adj_matrix);

    /*
    1. Adjacency matrix
    Undirected weighted graph

    vector<vector<int>> adj_matrix_weighted(vertex, vector<int>(vertex, 0));
    for (int i = 0; i < edges; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj_matrix_weighted[u][v] = wt;
        adj_matrix_weighted[v][u] = wt;
    }
    printGraph(adj_matrix_weighted);

    */

    /*
     1. Adjacency matrix
     Directed unweighted graph

    vector<vector<bool>> adj_matrix(vertex, vector<bool>(vertex, 0));
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
    }
    printGraph(adj_matrix);
    */

    /*
     1. Adjacency matrix
     Directed weighted graph

     vector<vector<int>> adj_matrix_weighted(vertex, vector<int>(vertex, 0));
     for (int i = 0; i < edges; i++){
         int u, v, wt;
         cin >> u >> v >> wt;
         adj_matrix_weighted[u][v] = wt;
     }
     printGraph(adj_matrix_weighted);
     */
}
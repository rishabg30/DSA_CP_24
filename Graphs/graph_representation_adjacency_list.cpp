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
Time complexity: O(V + E)
Space complexity: O(V + E)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

/*
Graphs representation:
1). Adjacency matrix
2). Adjacency list
*/

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Take Input here if needed
    */

    /*
    Undirected unweighted graph
    */
    int vertex, edges;
    cin >> vertex >> edges;
    vector<int> adj_list[vertex];

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    // Print the graph
    for (int i = 0; i < vertex; i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }

    /*
    Undirected weighted graph

    vector<pair<int, int>> adj_list_weighted[vertex];

    for (int i = 0; i < edges; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj_list_weighted[u].push_back(make_pair(v, wt));
        adj_list_weighted[v].push_back(make_pair(u, wt));
    }
    // Print the graph
    for (int i = 0; i < vertex; i++){
        cout << i << " -> ";
        for (int j = 0; j < adj_list_weighted[i].size(); j++)
        {
            cout << "(" << adj_list_weighted[i][j].first << " " << adj_list_weighted[i][j].second << ") ";
        }
        cout << endl;
    }
    */
}
#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int V, vector<int>adj[], vector<bool>&visited, int startNode) {
	visited[startNode] = true;

	//Traverse all it's neighbours if they are unvisited
	for (int i = 0; i < adj[startNode].size(); i++) {
		if (!visited[adj[startNode][i]]) {
			dfs_algorithm(V, adj, visited, adj[startNode][i]);
		}
	}
}
int findCircleNum(vector<vector<int>>& graph) {
	//Step 1: Convert given adjacency matrix to adjacency list

	int n = graph.size(), count = 0;
	vector<int>adjGraph[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				adjGraph[i].push_back(j);
				adjGraph[j].push_back(i);
			}
		}
	}

	//Step 2: Apply DFS/BFS to check provinces
	vector<bool>visited(n + 1, false);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			count++;
			dfs_algorithm(n, adjGraph, visited, i);
		}
	}
	return count;
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
	int n, m; cin >> n >> m;
	vector<vector<int>>graph(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	cout << findCircleNum(graph) << endl;
}
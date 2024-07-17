#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool dfs_algorithm(int V, vector<int>adj[], vector<bool>&visited, int startNode, int parentNode) {
	visited[startNode] = true;

	//Traverse the neighbours if not visited
	for (int i = 0; i < adj[startNode].size(); i++) {
		if (!visited[adj[startNode][i]]) {
			if (dfs_algorithm(V, adj, visited, adj[startNode][i], startNode) == true) {
				return true;
			}
		}
		else {
			// it is a visited node
			if (adj[startNode][i] != parentNode) {
				return true;
			}
		}
	}
	return false;
}
bool isCycle(int V, vector<int> adj[]) {
	vector<bool>visited(V + 1, false);
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			if (dfs_algorithm(V, adj, visited, i, -1) == true) {
				return true;
			}
		}
	}
	return false;
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

	int ver, edg; cin >> ver >> edg;
	vector<int>graph[ver];
	for (int i = 0; i < edg; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout << isCycle(ver, graph) << endl;
}
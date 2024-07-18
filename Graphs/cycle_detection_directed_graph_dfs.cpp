#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool dfs_algorithm(int startNode, int V, vector<int>adj[], vector<int>&visited,
                   vector<int>&pathVisited) {
	visited[startNode] = 1;
	pathVisited[startNode] = 1;
	//Traverse the neighbours if unvisited
	for (int i = 0; i < adj[startNode].size(); i++) {
		if (!visited[adj[startNode][i]]) {
			if (dfs_algorithm(adj[startNode][i], V, adj, visited, pathVisited) == true) {
				return true;
			}
		}
		else if (pathVisited[adj[startNode][i]] != 0) {
			return true;
		}
	}
	pathVisited[startNode] = 0;
	return false;
}
bool isCyclic(int V, vector<int> adj[]) {
	/*
	We will use the concept of pathVisited
	No two same nodes should be encountered in the same path
	*/
	vector<int>visited(V + 1, 0);
	vector<int>pathVisited(V + 1, 0);

	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			if (dfs_algorithm(i, V, adj, visited, pathVisited) == true) {
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
	}
	cout << isCyclic(ver, graph) << endl;
}
#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int V, vector<int>adj[], vector<bool>&visited, vector<int>&dfs_ans, int startNode) {
	visited[startNode] = true;
	dfs_ans.push_back(startNode);

	//Traverse it's neighbours if unvisited
	for (int i = 0; i < adj[startNode].size(); i++) {
		if (!visited[adj[startNode][i]]) {
			dfs_algorithm(V, adj, visited, dfs_ans, adj[startNode][i]);
		}
	}
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
	vector<bool>visited(V + 1, false);
	vector<int>dfs_ans;
	dfs_algorithm(V, adj, visited, dfs_ans, 0);
	return dfs_ans;
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
	vector<int>dfs = dfsOfGraph(ver, graph);
	printArray_1D(dfs);
}
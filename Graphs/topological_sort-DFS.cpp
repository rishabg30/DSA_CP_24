#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

/*

Topological Sort only applies in DAG [Directed Acyclic Graph]
It says Linear ordering of vertices such that if there is an edge from u->v then u vertex must always
come before v vertex in the ordering.

*/

void dfs_algorithm(int startNode, int V, vector<int>adj[], vector<int>&visited, stack<int>&st) {
	visited[startNode] = 1;

	//Traverse it's neighbours if unvisited
	for (int i = 0; i < adj[startNode].size(); i++) {
		if (!visited[adj[startNode][i]]) {
			dfs_algorithm(adj[startNode][i], V, adj, visited, st);
		}
	}
	st.push(startNode);
}
vector<int> topoSort(int V, vector<int> adj[]) {
	vector<int>visited(V + 1, 0);
	stack<int>st;

	//Start traversing the nodes
	for (int i = 0; i < V; i++) {
		if (!visited[i]) {
			dfs_algorithm(i, V, adj, visited, st);
		}
	}

	vector<int>ans;
	while (st.size() != 0) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
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
	vector<int>ans = topoSort(ver, graph);
	printArray_1D(ans);
}
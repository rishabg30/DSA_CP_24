#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O()
Space complexity: O()
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool isCyclePresent(int V, vector<int> adj[], vector<bool>&visited, int startNode) {
	// we will store {curr_node,curr_node_parent}
	queue<pair<int, int>>q;
	q.push(make_pair(startNode, -1));
	visited[startNode] = true;

	while (q.size() != 0) {
		int curr_node = q.front().first;
		int curr_node_parent = q.front().second;
		q.pop();

		//Traverse it's neighbours if unvisited
		for (int i = 0; i < adj[curr_node].size(); i++) {
			if (!visited[adj[curr_node][i]]) {
				q.push(make_pair(adj[curr_node][i], curr_node));
				visited[adj[curr_node][i]] = true;
			}
			// It's already visited
			else if (adj[curr_node][i] != curr_node_parent) {
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
			if (isCyclePresent(V, adj, visited, i) == true) {
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
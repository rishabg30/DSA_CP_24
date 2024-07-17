#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/


void bfs_algorithm(int V, vector<int>adj[], vector<bool>&visited, vector<int>&bfs_ans) {
	queue<int>q;
	q.push(0); //Took it as a start point [root node]
	visited[0] = true;

	while (q.size() != 0) {
		int curr_node = q.front();
		q.pop();
		bfs_ans.push_back(curr_node);

		//Traverse to curr_node neighbours and if unvisited push it in queue
		for (int i = 0; i < adj[curr_node].size(); i++) {
			if (!visited[adj[curr_node][i]]) {
				visited[adj[curr_node][i]] = true;
				q.push(adj[curr_node][i]);
			}
		}
	}
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
	vector<bool>visited(V, false);
	vector<int>bfs_ans;
	bfs_algorithm(V, adj, visited, bfs_ans);
	return bfs_ans;
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
	vector<int>bfs = bfsOfGraph(ver, graph);
	printArray_1D(bfs);
}
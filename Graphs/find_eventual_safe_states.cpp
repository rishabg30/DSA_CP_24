#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool dfs_algorithm(int startNode, vector<vector<int>>& graph, vector<int>&visited,
                   vector<int>&pathVisited, vector<int>&checkSafeNodes) {
	visited[startNode] = 1;
	pathVisited[startNode] = 1;
	checkSafeNodes[startNode] = 0;

	//Traverse it's neighbours if unvisited
	for (int i = 0; i < graph[startNode].size(); i++) {
		if (!visited[graph[startNode][i]]) {
			if (dfs_algorithm(graph[startNode][i], graph, visited, pathVisited, checkSafeNodes) == true) {
				checkSafeNodes[startNode] = 0;
				return true;
			}
		}
		//neighbour is already visited, checking if cycle is created
		else if (pathVisited[graph[startNode][i]] != 0) {
			return true;
		}
	}
	checkSafeNodes[startNode] = 1;
	pathVisited[startNode] = 0;
	return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int>visited(n, 0);
	vector<int>pathVisited(n, 0);
	vector<int>checkSafeNodes(n, 0);

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			dfs_algorithm(i, graph, visited, pathVisited, checkSafeNodes);
		}
	}
	vector<int>safeNodes;
	for (int i = 0; i < n; i++) {
		if (checkSafeNodes[i] == 1) {
			safeNodes.push_back(i);
		}
	}
	return safeNodes;
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
	vector<int>ans = eventualSafeNodes(graph);
}
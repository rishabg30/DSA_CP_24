#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool dfs_algorithm(int startNode, int initial_col, vector<vector<int>>& adj, vector<int>&color) {
	color[startNode] = initial_col;

	//Traverse it's neighbours
	for (int i = 0; i < adj[startNode].size(); i++) {
		//if neighbour node is not coloured yet, color it with opposite color and apply dfs_algorithm again
		if (color[adj[startNode][i]] == -1) {
			if (dfs_algorithm(adj[startNode][i], !initial_col, adj, color) == false) {
				return false;
			}
		}
		/*
		if neighbour is coloured
		check -> if same color, return false as this graph cannot be bipartite
		else continue
		*/
		else if (color[adj[startNode][i]] == initial_col) {
			return false;
		}
	}
	return true;
}
bool isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int>color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (dfs_algorithm(i, 0, graph, color) == false) {
				return false;
			}
		}
	}
	return true;
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
	vector<vector<int>>graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
	cout << isBipartite(graph) << endl;
}
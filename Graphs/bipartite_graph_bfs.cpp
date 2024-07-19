#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool checkBipartite(int startNode, int V, vector<vector<int>>& adj, vector<int>&color) {
	color[startNode] = 0;

	queue<int>q;
	q.push(startNode);

	while (q.size() != 0) {
		int curr_node = q.front();
		q.pop();

		/*
		Start traversing it's neighbours
		*/
		for (int i = 0; i < adj[curr_node].size(); i++) {
			//if neighbour node is not coloured yet, color it with opposite color and push it in queue
			if (color[adj[curr_node][i]] == -1) {
				color[adj[curr_node][i]] = !color[curr_node];
				q.push(adj[curr_node][i]);
			}
			/*
			if neighbour is coloured
			check -> if same color, return false as this graph cannot be bipartite
			else continue
			*/
			else if (color[adj[curr_node][i]] == color[curr_node]) {
				return false;
			}
		}
	}
	return true;
}
bool isBipartite(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int>color(n, -1);
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			if (checkBipartite(i, n, graph, color) == false) {
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
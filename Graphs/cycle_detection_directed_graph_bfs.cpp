#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool isCyclic(int V, vector<int> adj[]) {
	/*
	Here we will use Kahn's topological algorithm
	If there is no cycle present vector should contain all elements at the end
	i.e. vector.size() == V
	*/

	//Step1: Create an inDegree vector
	vector<int>inDegree(V + 1, 0);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			inDegree[adj[i][j]]++;
		}
	}

	//Step2: Push all elements with inDegree 0 inside queue
	queue<int>q;
	vector<int>ans;
	for (int i = 0; i < V; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (q.size() != 0) {
		int curr_node = q.front();
		q.pop();
		ans.push_back(curr_node);

		/*
		Traverse it's neighbours and reduce their inDegree by 1
		if inDegree becomes 0 push it inside queue
		*/
		for (int i = 0; i < adj[curr_node].size(); i++) {
			inDegree[adj[curr_node][i]]--;
			if (inDegree[adj[curr_node][i]] == 0) {
				q.push(adj[curr_node][i]);
			}
		}
	}
	return (ans.size() == V) ? 0 : 1;
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
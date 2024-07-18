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

-> When applied with BFS: Known as Kahn's Algorithm

*/

vector<int> topoSort(int V, vector<int> adj[]) {
	//Step1: Create a inDegree vector

	vector<int>inDegree(V, 0);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			inDegree[adj[i][j]]++;
		}
	}

	queue<int>q;
	vector<int>ans;
	//Step2: Push all elements with inDegree 0 into the queue
	for (int i = 0; i < V; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (q.size() != 0) {
		/*
		Start popping out elements and decrease their inDegree by 1
		as soon as InDegree of particular element becomes 0, push it in queue
		*/
		int curr_node = q.front();
		q.pop();
		ans.push_back(curr_node);

		//Traversing neighbours if unvisited
		for (int i = 0; i < adj[curr_node].size(); i++) {
			inDegree[adj[curr_node][i]]--;
			if (inDegree[adj[curr_node][i]] == 0) {
				q.push(adj[curr_node][i]);
			}
		}
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
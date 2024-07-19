#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(V + 2E)
Space complexity: O(V)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	//Step 1: Convert it into adjacency list

	vector<int>adj[numCourses];
	for (int i = 0; i < prerequisites.size(); i++) {
		int u = prerequisites[i][0];
		int v = prerequisites[i][1];
		adj[u].push_back(v);
	}

	//Create a inDegree vector
	vector<int>inDegree(numCourses, 0);
	for (int i = 0; i < numCourses; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			inDegree[adj[i][j]]++;
		}
	}

	//Push elements whose inDegree is 0 inside queue
	queue<int>q;
	vector<int>ans;
	for (int i = 0; i < numCourses; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}

	while (q.size() != 0) {
		int curr_node = q.front();
		q.pop();
		ans.push_back(curr_node);

		/*
		Traverse the neighbours and reduce inDegree by 1
		as soon inDegree becomes 0, push them inside queue.
		*/
		for (int i = 0; i < adj[curr_node].size(); i++) {
			inDegree[adj[curr_node][i]]--;
			if (inDegree[adj[curr_node][i]] == 0) {
				q.push(adj[curr_node][i]);
			}
		}
	}
	return (ans.size() == numCourses) ? 1 : 0;
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
	int numCourses = 2;
	vector<vector<int>>prerequisites = {{1, 0}};
	cout << canFinish(numCourses, prerequisites) << endl;
}
#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int orangesRotting(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();

	//This problem is typically targets BFS Algorithm
	vector<vector<int>>visited(n, vector<int>(m, false));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

	/*
	Push all elements with values 2 inside queue as they will be rotten by time = 0 sec
	and will be treated as a starting point
	*/

	// it will store {{curr_row,curr_col}, time}
	queue <pair<pair<int, int>, int>>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 2) {
				q.push({{i, j}, 0});
				visited[i][j] = 1;
			}
			else {
				visited[i][j] = 0;
			}
		}
	}

	int total_time = 0;
	while (q.size() != 0) {
		int curr_row = q.front().first.first;
		int curr_col = q.front().first.second;
		int inital_time = q.front().second;
		q.pop();

		total_time = max(total_time, inital_time);

		// Traverse neighbours if unvisited
		for (int d = 0; d < dirS.size(); d++) {
			int nrow = curr_row + dirS[d][0];
			int ncol = curr_col + dirS[d][1];

			if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0
			        && grid[nrow][ncol] == 1) {
				q.push({{nrow, ncol}, inital_time + 1});
				visited[nrow][ncol] = 2;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && visited[i][j] != 2) {
				return -1;
			}
		}
	}
	return total_time;
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
	vector<vector<int>>grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	cout << orangesRotting(grid) << endl;
}
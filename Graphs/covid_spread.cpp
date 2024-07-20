#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

//Similar question as rotten oranges
int helpaterp(vector<vector<int>> hospital) {

	int n = hospital.size(), m = hospital[0].size();
	//Here we will apply BFS algorithm
	queue<pair<pair<int, int>, int>>q;
	vector<vector<int>>visited(n, vector<int>(m));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};

	//Traverse in the grid and push all grid cells with values 2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (hospital[i][j] == 2) {
				// Affected ones
				q.push({{i, j}, 0});
				visited[i][j] = 1;
			}
			else {
				visited[i][j] = 0;
			}
		}
	}

	int max_time = 0;
	while (q.size() != 0) {
		int curr_row = q.front().first.first;
		int curr_col = q.front().first.second;
		int curr_time = q.front().second;
		q.pop();
		max_time = max(max_time, curr_time);

		//Traverse it's neighbours if unvisited
		for (int d = 0; d < dirS.size(); d++) {
			int nrow = curr_row + dirS[d][0];
			int ncol = curr_col + dirS[d][1];

			if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0
			        && hospital[nrow][ncol] == 1) {
				q.push({{nrow, ncol}, curr_time + 1});
				visited[nrow][ncol] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (hospital[i][j] == 1 && visited[i][j] != 1) {
				return -1;
			}
		}
	}
	return max_time;
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
	vector<vector<int>>arr(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << helpaterp(arr) << endl;
}
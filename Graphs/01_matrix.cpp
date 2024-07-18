#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>>visited(n, vector<int>(m));
	vector<vector<int>>ans(n, vector<int>(m, 0));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	queue<pair<pair<int, int>, int >> q;

	//We will put all cells having 0 in the queue initally as they all are starting points
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 0) {
				q.push({{i, j}, 0});
				visited[i][j] = 1;
			}
			else {
				visited[i][j] = 0;
			}
		}
	}
	while (q.size() != 0) {
		int curr_row = q.front().first.first;
		int curr_col = q.front().first.second;
		int curr_step = q.front().second;
		q.pop();
		ans[curr_row][curr_col] = curr_step;

		// Traverse all its neighbours if still unvisited
		for (int d = 0; d < dirS.size(); d++) {
			int nrow = curr_row + dirS[d][0];
			int ncol = curr_col + dirS[d][1];

			if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == false) {
				visited[nrow][ncol] = true;
				q.push({{nrow, ncol}, curr_step + 1});
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
	int n, m; cin >> n >> m;
	vector<vector<int>>matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrix[i][j];
		}
	}
	vector<vector<int>>ans = updateMatrix(matrix);
	printArray_2D(ans);
}
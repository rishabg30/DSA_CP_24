#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int sr, int sc, vector<vector<char>>&grid, vector<vector<bool>>&visited,
                   vector<vector<int>>&dirS) {
	visited[sr][sc] = true;

	// Traverse it's neighbours if they are unvisited
	for (int d = 0; d < dirS.size(); d++) {
		int nrow = sr + dirS[d][0];
		int ncol = sc + dirS[d][1];

		if (nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() &&
		        visited[nrow][ncol] == false && grid[nrow][ncol] == '1') {
			dfs_algorithm(nrow, ncol, grid, visited, dirS);
		}
	}
}
int numIslands(vector<vector<char>>& grid) {
	int n = grid.size(), m = grid[0].size(), count = 0;
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == '1') {
				dfs_algorithm(i, j, grid, visited, dirS);
				count++;
			}
		}
	}
	return count;
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
	vector<vector<char>>grid(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	cout << numIslands(grid) << endl;
}
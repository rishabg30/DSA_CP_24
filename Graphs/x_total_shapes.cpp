#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int sr, int sc, vector<vector<char>>& grid, vector<vector<int>>& visited,
                   vector<vector<int>>&dirS) {
	int n = grid.size(), m = grid[0].size();
	visited[sr][sc] = 1;

	//Traverse across neighbours if unvisited
	for (int d = 0; d < dirS.size(); d++) {
		int nrow = sr + dirS[d][0];
		int ncol = sc + dirS[d][1];

		if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0
		        && grid[nrow][ncol] == 'X') {
			dfs_algorithm(nrow, ncol, grid, visited, dirS);
		}
	}
}
int xShape(vector<vector<char>>& grid) {
	int n = grid.size(), m = grid[0].size(), count = 0;
	vector<vector<int>>visited(n, vector<int>(m, 0));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, 1}, {0, -1}};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == 'X') {
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
	cout << xShape(grid) << endl;
}
#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

/*Similar Question as Surrounded Regions*/

void dfs_algorithm(int curr_row, int curr_col, vector<vector<int>>& grid,
                   vector<vector<int>>&visited, vector<vector<int>>& dirS) {
	int n = grid.size(), m = grid[0].size();
	visited[curr_row][curr_col] = 1;

	//Traversing neighbours if unvisited
	for (int d = 0; d < dirS.size(); d++) {
		int nrow = curr_row + dirS[d][0];
		int ncol = curr_col + dirS[d][1];

		if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == false
		        && grid[nrow][ncol] == 1) {
			dfs_algorithm(nrow, ncol, grid, visited, dirS);
		}
	}
}
int numEnclaves(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>>visited(n, vector<int>(m, 0));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

	//Traversing boundaries of matrix

	//Traversing first and last row of matrix
	for (int j = 0; j < m; j++) {
		if (!visited[0][j] && grid[0][j] == 1) {
			dfs_algorithm(0, j, grid, visited, dirS);
		}
		if (!visited[n - 1][j] && grid[n - 1][j] == 1) {
			dfs_algorithm(n - 1, j, grid, visited, dirS);
		}
	}

	//Traversing first and last column of matrix
	for (int i = 0; i < n; i++) {
		if (!visited[i][0] && grid[i][0] == 1) {
			dfs_algorithm(i, 0, grid, visited, dirS);
		}
		if (!visited[i][m - 1] && grid[i][m - 1] == 1) {
			dfs_algorithm(i, m - 1, grid, visited, dirS);
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1 && visited[i][j] == 0) {
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
	vector<vector<int>>grid(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	cout << numEnclaves(grid) << endl;
}
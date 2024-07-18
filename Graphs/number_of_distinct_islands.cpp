#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int sr, int sc, vector<vector<int>>& grid, vector<vector<int>>& visited,
                   vector<vector<int>>& dirS, vector<pair<int, int>>&ans, int baserow, int basecol) {
	int n = grid.size(), m = grid[0].size();
	visited[sr][sc] = 1;
	ans.push_back({sr - baserow, sc - basecol});

	//Traversing the neighbours if unvisited
	for (int d = 0; d < dirS.size(); d++) {
		int nrow = sr + dirS[d][0];
		int ncol = sc + dirS[d][1];

		if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == 0
		        && grid[nrow][ncol] == 1) {
			dfs_algorithm(nrow, ncol, grid, visited, dirS, ans, baserow, basecol);
		}
	}
}
int countDistinctIslands(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>>visited(n, vector<int>(m, 0));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	//To store distinct islands we will use set data structure
	set<vector<pair<int, int>>>st;

	//Traversing the entire grid
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && grid[i][j] == 1) {
				vector<pair<int, int>>vec; //will store the islands
				dfs_algorithm(i, j, grid, visited, dirS, vec, i, j);
				st.insert(vec);
			}
		}
	}
	return st.size();
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
	cout << countDistinctIslands(grid) << endl;
}
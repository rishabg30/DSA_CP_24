#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<char>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void dfs_algorithm(int curr_row, int curr_col, vector<vector<char>>& board,
                   vector<vector<int>>&visited, vector<vector<int>>& dirS) {
	int n = board.size(), m = board[0].size();
	visited[curr_row][curr_col] = 1;

	//Traversing neighbours if unvisited
	for (int d = 0; d < dirS.size(); d++) {
		int nrow = curr_row + dirS[d][0];
		int ncol = curr_col + dirS[d][1];

		if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == false
		        && board[nrow][ncol] == 'O') {
			dfs_algorithm(nrow, ncol, board, visited, dirS);
		}
	}
}
void solve(vector<vector<char>>& board) {
	int n = board.size(), m = board[0].size();

	/*
	Observation is we cannot convert 0s placed at boundary and their
	touching ones
	Therefore lets traverse all boundary 0s and flag them with their neighbours
	as not possible to be convertable.
	*/

	vector<vector<int>>visited(n, vector<int>(m, 0));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};

	//Traversing boundaries of matrix

	//Traversing first and last row of matrix
	for (int j = 0; j < m; j++) {
		if (!visited[0][j] && board[0][j] == 'O') {
			dfs_algorithm(0, j, board, visited, dirS);
		}
		if (!visited[n - 1][j] && board[n - 1][j] == 'O') {
			dfs_algorithm(n - 1, j, board, visited, dirS);
		}
	}

	//Traversing first and last column of matrix
	for (int i = 0; i < n; i++) {
		if (!visited[i][0] && board[i][0] == 'O') {
			dfs_algorithm(i, 0, board, visited, dirS);
		}
		if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
			dfs_algorithm(i, m - 1, board, visited, dirS);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'O' && visited[i][j] == 0) {
				board[i][j] = 'X';
			}
		}
	}
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
	vector<vector<char>>board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	solve(board);
	printArray_2D(board);
}
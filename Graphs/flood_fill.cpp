#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N * M)
Space complexity: O(N * M)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int n = image.size(), m = image[0].size();
	vector<vector<int>>ans = image; // copy the given vector
	vector<vector<bool>>visited(n, vector<bool>(m, false));
	vector<vector<int>>dirS = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
	queue < pair<int, pair<int, int>>>q; // it will store {curr_color , {curr_row, curr_col}}

	q.push({image[sr][sc], {sr, sc}});
	visited[sr][sc] = true;

	while (q.size() != 0) {
		int curr_color = q.front().first;
		int curr_row = q.front().second.first;
		int curr_col = q.front().second.second;
		q.pop();
		ans[curr_row][curr_col] = color;

		//Traverse it's neighbours if they are unvisited and have same color
		for (int d = 0; d < dirS.size(); d++) {
			int nrow = curr_row + dirS[d][0];
			int ncol = curr_col + dirS[d][1];

			if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && visited[nrow][ncol] == false &&
			        image[nrow][ncol] == curr_color) {
				q.push({curr_color, {nrow, ncol}});
				visited[nrow][ncol] = true;
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
	vector<vector<int>>graph(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
		}
	}
	int sr, sc, color; cin >> sr >> sc >> color;
	vector<vector<int>>ans = floodFill(graph, sr, sc, color);
	printArray_2D(ans);
}
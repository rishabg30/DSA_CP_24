#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int maxArea(vector<int>& height) {
	int n = height.size();
	int start = 0, end = n - 1, ans = -1e9;

	while (start <= end) {
		int curr_ans = (end - start) * min(height[start], height[end]);
		ans = max(ans, curr_ans);

		if (height[start] > height[end]) {
			end--;
		}
		else if (height[start] < height[end]) {
			start++;
		}
		else {
			start++;
			end--;
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
	int n; cin >> n;
	vector<int>height(n);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	cout << maxArea(height) << endl;
}
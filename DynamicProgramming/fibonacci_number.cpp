#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(N)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/
int calculate_fibonacci_tab(int n, vector<int>&dp) {
	if (n == 0 || n == 1) {
		return n;
	}
	dp[0] = 0, dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
int calculate_fibonacci_memo(int n, vector<int>&dp) {
	if (n == 0 || n == 1) {
		return dp[n] = n;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	int smallAns = calculate_fibonacci_memo(n - 1, dp) + calculate_fibonacci_memo(n - 2, dp);
	return dp[n] = smallAns;
}
int fib(int n) {

	vector<int>dp(n + 1, -1);
	return calculate_fibonacci_tab(n, dp);
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
	cout << fib(n) << endl;
}
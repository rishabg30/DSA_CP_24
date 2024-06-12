#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(log(N))
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int power(int a, int b, int m) {
	if (b == 0) {
		return 1;
	}

	int half_ans = power(a, b / 2, m);
	int ans;

	if (b % 2 == 0) {
		ans = 1LL * half_ans * half_ans % m;
	}
	else {
		ans = 1LL * half_ans * half_ans % m;
		ans = 1LL * ans * a % m;
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
	int a, b; cin >> a >> b;
	cout << power(a, b, 1e7) << endl;
}
#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void segregate0and1(vector<int> &arr) {
	int n = arr.size();
	int sptr = 0, eptr = 0;

	while (eptr < n) {
		if (arr[eptr] == 0) {
			swap(arr[sptr], arr[eptr]);
			sptr++;
		}
		eptr++;
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
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	segregate0and1(arr);
	printArray_1D(arr);
}
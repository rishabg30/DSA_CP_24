#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void sortColors(vector<int>& arr) {
	int n = arr.size();

	//This is a standard problem solved by Dutch National Flag Algorithm
	int start = 0, mid = 0, end = n - 1;
	while (mid <= end) {
		if (arr[mid] == 1) {
			mid++;
		}
		else if (arr[mid] == 0) {
			swap(arr[start], arr[mid]);
			start++;
			mid++;
		}
		else {
			swap(arr[mid], arr[end]);
			end--;
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

	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sortColors(arr);
	printArray_1D(arr);
}

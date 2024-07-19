#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

void reverse_array(int arr[], int si, int ei) {
	while (si <= ei) {
		swap(arr[si], arr[ei]);
		si++;
		ei--;
	}
}
void rotateArr(int arr[], int d, int n) {
	if (d > n) {
		d = d % n;
	}
	/*
	For right rotation:
	right rotation = n - d

	d = n - d;

	If d < 0, d = d + n
	*/
	//Step1: reverse array from 0 to d index

	reverse_array(arr, 0, d - 1);
	reverse_array(arr, d, n - 1);
	reverse_array(arr, 0, n - 1);
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
	int n = 10, d = 3;
	int arr[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	rotateArr(arr, d, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
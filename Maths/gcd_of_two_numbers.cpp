#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(log(N))
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int findGCD(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > 0) {
			a = a % b;
		}
		if (b > 0) {
			b = b % a;
		}
	}
	if (a == 0)return b;
	else return a;
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
	cout << findGCD(a, b) << endl;
}
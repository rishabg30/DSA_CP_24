#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O()
Space complexity: O()
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

string minWindow(string s, string t) {
	int n = s.size(), m = t.size();
	string ans;

	/*
	If string t length is greater than string s length, then it is not possible to return the minimum
	window substring of s such that every character in t (including duplicates) is included in the window.
	*/
	if (m >= n) {
		if (m == n) {
			return s;
		}
		else return ans;
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
	string s, t; cin >> s >> t;
	cout << minWindow(s, t) << endl;
}
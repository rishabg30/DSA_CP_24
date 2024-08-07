#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O()
Space complexity: O()
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int longestSubstring(string s, int k) {
	int n = s.size();
	int start = 0, end = 0, max_window_size = 0;
	map<char, int>mp;

	while (end < n) {
		mp[s[end]]++;

		/*
		It will be a part of window if all element's frequencies present inside our map
		is >=k
		*/

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
	string s; cin >> s;
	int k; cin >> k;
	cout << longestSubstring(s, k) << endl;
}
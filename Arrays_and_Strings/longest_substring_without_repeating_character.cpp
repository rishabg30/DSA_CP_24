#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O()
Space complexity: O()
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int lengthOfLongestSubstring(string str) {
	int n = str.size();
	map<int, int>mp;

	int start = 0, end = 0, max_window = 0;
	while (end < n) {
		mp[str[end]]++;
		/*
		Until freq of any character is > 1 reduce the window as
		window is not possible
		*/
		while (mp[str[end]] > 1) {
			mp[str[start]]--;
			start++;
		}
		int curr_window = (end - start) + 1;
		max_window = max(max_window, curr_window);
		end++;
	}
	return max_window;
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
	string str; cin >> str;
	cout << lengthOfLongestSubstring(str) << endl;
}
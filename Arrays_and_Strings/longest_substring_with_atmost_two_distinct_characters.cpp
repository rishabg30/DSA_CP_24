#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int lengthOfLongestSubstringTwoDistinct(string str) {
	int n = str.size();
	int start = 0, end = 0, max_window_size = 0;
	map<char, int>mp;

	while (end < n) {
		mp[str[end]]++;

		/*
		if there are more than two distinct characters we will reduce the window size
		till there are distinct characters <=2
		*/
		while (mp.size() > 2) {
			mp[str[start]]--;
			if (mp[str[start]] == 0) {
				mp.erase(str[start]);
			}
			start++;
		}

		int curr_window = end - start + 1;
		max_window_size = max(curr_window, max_window_size);
		end++;
	}
	return max_window_size;
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
	cout << lengthOfLongestSubstringTwoDistinct(str) << endl;
}
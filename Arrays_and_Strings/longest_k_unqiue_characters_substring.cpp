#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int longestKSubstr(string str, int k) {
	int n = str.size();
	int start = 0, end = 0, max_window = -1;
	map<char, int>mp;

	while (end < n) {
		//Push the character in the map
		mp[str[end]]++;

		/*
		if map will contain more than k distinct characters
		then it cannot be treated as a window
		*/
		while (mp.size() > k) {
			mp[str[start]]--;
			if (mp[str[start]] == 0) {
				mp.erase(str[start]);
			}
			start++;
		}

		//if there are k distinct characters then only it can be treated as a window
		if (mp.size() == k) {
			int curr_window = end - start + 1;
			max_window = max(curr_window, max_window);
		}
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
	int k; cin >> k;
	cout << longestKSubstr(str, k) << endl;
}
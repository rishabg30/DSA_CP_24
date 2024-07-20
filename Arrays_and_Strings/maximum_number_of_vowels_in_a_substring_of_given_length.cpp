#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

/*
Time complexity: O(N)
Space complexity: O(1)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

int maxVowels(string s, int k) {
	int n = s.size(), count = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			count++;
		}
	}

	int start = 0, end = k, max_window_size = 0;
	max_window_size = max(max_window_size, count);
	while (end < n) {
		if (s[end] == 'a' || s[end] == 'e' || s[end] == 'i' || s[end] == 'o' || s[end] == 'u') {
			count++;
		}

		if (end - start + 1 > k) {
			if (s[start] == 'a' || s[start] == 'e' || s[start] == 'i' || s[start] == 'o' || s[start] == 'u') {
				count--;
			}
			start++;
		}
		max_window_size = max(max_window_size, count);
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
	string s; cin >> s;
	int k; cin >> k;
	cout << maxVowels(s, k) << endl;
}
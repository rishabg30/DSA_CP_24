#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int>&arr) {for (auto it : arr) {cout << it << " ";} cout << endl;}
void printArray_2D(vector<vector<int>>&arr) {for (auto it : arr) {for (auto it2 : it) {cout << it2 << " ";} cout << endl;}}

class TreeNode {
public:
	int data;
	TreeNode *left, *right;

	TreeNode(int data) {
		this->data = data;
		left = right = NULL;
	}
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

TreeNode *createBinaryTree() {
	int x; cin >> x;
	if (x == -1) {
		cout << -1 << endl;
		return NULL;
	}
	cout << x << endl;
	TreeNode *temp = new TreeNode(x);

	//Create leftside
	cout << "Enter left child of node " << temp->data << ": " << endl;
	temp->left = createBinaryTree();

	//Create rightside
	cout << "Enter right child of node " << temp->data << ": " << endl;
	temp->right = createBinaryTree();
	return temp;
}

vector<int> verticalOrder(TreeNode *root) {
	if (root == NULL) {
		return {};
	}

	//{x_axis, {y_axis, nodes}}
	map<int, map<int, vector<int>>>mp;
	vector<int>ans;
	//{node, {x_axis, y_axis}}
	queue<pair<TreeNode *, pair<int, int>>>q;
	q.push(make_pair(root, make_pair(0, 0)));

	while (q.size() != 0) {
		auto it = q.front();
		q.pop();

		TreeNode *node = it.first;
		int x_axis = it.second.first, y_axis = it.second.second;
		mp[x_axis][y_axis].push_back(node->data);

		if (node->left) {
			q.push(make_pair(node->left, make_pair(x_axis - 1, y_axis + 1)));
		}
		if (node->right) {
			q.push(make_pair(node->right, make_pair(x_axis + 1, y_axis + 1)));
		}
	}

	for (auto i : mp) {
		for (auto j : i.second) {
			for (auto k : j.second) {
				ans.push_back(k);
			}
		}
	}
	return ans;
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
	TreeNode *node = createBinaryTree();
	vector<int>ans = verticalOrder(node);
	printArray_1D(ans);
}
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
Time complexity: O()
Space complexity: O()
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

vector <int> bottomView(TreeNode *root) {
	if (root == NULL) {
		return {};
	}
	vector<int>bottomViewElements;

	//{element, x_axis}
	queue < pair<TreeNode*, int>>q;
	map<int, TreeNode*> mp;
	q.push(make_pair(root, 0));

	while (q.size() != 0) {
		int curr_queue_size = q.size();

		for (int i = 0; i < curr_queue_size; i++) {
			TreeNode *node = q.front().first;
			int curr_x_axis = q.front().second;
			q.pop();
			mp[curr_x_axis] = node;


			if (node->left)q.push(make_pair(node->left, curr_x_axis - 1));
			if (node->right)q.push(make_pair(node->right, curr_x_axis + 1));
		}
	}
	for (auto it : mp) {
		bottomViewElements.push_back(it.second->data);
	}
	return bottomViewElements;
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
	vector<int>ans = bottomView(node);
	printArray_1D(ans);
}
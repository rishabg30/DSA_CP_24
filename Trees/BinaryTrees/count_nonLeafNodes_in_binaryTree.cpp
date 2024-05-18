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
Space complexity: O(1)
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

int countNonLeafNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	//Base condition for a leaf node
	if (root->left == NULL && root->right == NULL) {
		return 0;
	}

	int leftTreeNonLeafNodes = countNonLeafNodes(root->left);
	int rightTreeNonLeafNodes = countNonLeafNodes(root->right);

	//1 indicating we got the non-leaf node
	return 1 + leftTreeNonLeafNodes + rightTreeNonLeafNodes;
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
	cout << countNonLeafNodes(node) << endl;
}
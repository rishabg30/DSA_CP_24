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

bool isIdentical(TreeNode *root1, TreeNode *root2) {
	if (root1 == NULL && root2 == NULL) {
		return true;
	}
	if ((root1 == NULL && root2) || (root1 && root2 == NULL)) {
		return false;
	}
	// Base condition for tree to be identical
	if (root1->data != root2->data) {
		return false;
	}
	return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
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
	TreeNode *node1 = createBinaryTree();
	TreeNode *node2 = createBinaryTree();
	cout << isIdentical(node1, node2) << endl;
}
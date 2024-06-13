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
Time complexity: O(N * N)
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

int findPosition(int in[], int target, int startPos, int endPos) {
	for (int i = startPos; i <= endPos; i++) {
		if (in[i] == target) {
			return i;
		}
	}
	return -1;
}
TreeNode *myTree(int in[], int pre[], int inOrderStart, int inOrderEnd, int index) {
	//index showing preOrder starting point
	if (inOrderStart > inOrderEnd) {
		return NULL;
	}

	TreeNode *root = new TreeNode(pre[index]);
	//Find out the position of this root node in inOrder
	int pos = findPosition(in, pre[index], inOrderStart, inOrderEnd);

	//Build left tree
	root->left = myTree(in, pre, inOrderStart, pos - 1, index + 1);
	//Build right tree
	root->right = myTree(in, pre, pos + 1, inOrderEnd, (index + pos - inOrderStart) + 1);
	return root;
}
TreeNode* buildTree(int in[], int pre[], int n) {
	return myTree(in, pre, 0, n - 1, 0);
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
}
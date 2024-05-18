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

int height(TreeNode *node, bool &curr_balanced) {
	if (node == NULL) {
		return 0;
	}
	int leftSubtreeheight = height(node->left, curr_balanced);
	int rightSubtreeheight = height(node->right, curr_balanced);
	if (abs(leftSubtreeheight - rightSubtreeheight) > 1) {
		curr_balanced = false;
	}
	return 1 + max(leftSubtreeheight, rightSubtreeheight);
}
bool isBalanced(TreeNode *root) {
	if (root == NULL) {
		return true;
	}
	bool curr_balanced = true;
	height(root, curr_balanced);
	return curr_balanced;
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
	cout << isBalanced(node) << endl;
}
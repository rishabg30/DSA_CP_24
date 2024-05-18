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

bool checkParent(TreeNode *root, int a , int b) {
	if (root == NULL) {
		return false;
	}
	//Base condition both left and right child must be present
	if (root->left && root->right) {
		if (root->left->data == a && root->right->data == b) {
			return true;
		}
		if (root->left->data == b && root->right->data == a) {
			return true;
		}
	}
	return checkParent(root->left, a, b) || checkParent(root->right, a, b);
}
void levelOrderTraversal(TreeNode *root, int givennode, int &curr_depth) {
	queue<TreeNode *>q;
	q.push(root);
	int curr_level = 0;

	while (q.size() != 0) {
		int curr_queue_size = q.size();

		for (int i = 0; i < curr_queue_size; i++) {
			TreeNode *node = q.front();
			q.pop();

			if (node->data == givennode) {
				curr_depth = curr_level;
			}
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
		curr_level++;
	}
}
bool isCousins(TreeNode *root, int a, int b) {
	if (root == NULL) {
		return false;
	}

	//First find out level/depth of both a and b
	int depthOfNode_a = -1;
	int depthOfNode_b = -1;
	levelOrderTraversal(root, a, depthOfNode_a);
	levelOrderTraversal(root, b, depthOfNode_b);

	if (depthOfNode_a != depthOfNode_b) {
		return false;
	}
	if (depthOfNode_a == -1 || depthOfNode_b == -1) {
		return false;
	}

	//Check if they have same parent

	bool sameParent = checkParent(root, a, b);
	if (sameParent == true) {
		return false;
	}
	return true;
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
	cout << isCousins(node, 2 , 3);
}
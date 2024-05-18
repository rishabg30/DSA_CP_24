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
Space complexity: O(height of tree)
*/


/*-------------------Write code downwards--------------------------------------------------------------*/

TreeNode *createBinaryTree() {
	int x; cin >> x;
	if (x == -1)return NULL;

	TreeNode *temp = new TreeNode(x);

	//Create leftside
	cout << "Enter left child of node: " << endl;
	temp->left = createBinaryTree();

	//Create rightside
	cout << "Enter right child of node: " << endl;
	temp->right = createBinaryTree();
	return temp;
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

	cout << "Enter the root node: " << endl;
	TreeNode *root;
	root = createBinaryTree();
}
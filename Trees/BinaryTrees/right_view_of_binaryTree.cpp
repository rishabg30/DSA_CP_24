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

vector<int> rightView(TreeNode *root) {
	if (root == NULL) {
		return {};
	}
	vector<int>rightViewElements;
	queue<TreeNode *>q;
	q.push(root);

	while (q.size() != 0) {
		int curr_queue_size = q.size();
		int count = 0;
		for (int i = 0; i < curr_queue_size; i++) {
			TreeNode *node = q.front();
			q.pop();
			count++;

			if (count == curr_queue_size) {
				rightViewElements.push_back(node->data);
			}
			if (node->left)q.push(node->left);
			if (node->right)q.push(node->right);
		}
	}
	return rightViewElements;
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
	vector<int>ans = rightView(node);
	printArray_1D(ans);
}
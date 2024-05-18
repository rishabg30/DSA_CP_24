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
Space complexity: O(N )
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

vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<vector<int>>ans;
	queue<TreeNode *>q;
	q.push(root);

	while (q.size() != 0) {
		int curr_queue_size = q.size();
		vector<int>curr_level_nodes;
		for (int i = 0; i < curr_queue_size; i++) {
			TreeNode *node = q.front();
			q.pop();
			curr_level_nodes.push_back(node->data);

			//If left child is present push it into the queue
			if (node->left) {
				q.push(node->left);
			}

			//If right child is present push it into the queue
			if (node->right) {
				q.push(node->right);
			}
		}
		ans.push_back(curr_level_nodes);
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
	vector<vector<int>>ans = levelOrder(node);
	printArray_2D(ans);
}
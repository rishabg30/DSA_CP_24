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

vector<int> inOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	stack<TreeNode *>st;
	stack<bool>visited;
	st.push(root);
	visited.push(0);


	vector<int>ans;
	while (st.size() != 0) {
		//Take out the topmost node from stack and its count from visited stack
		TreeNode *node = st.top();
		st.pop();
		bool count = visited.top();
		visited.pop();

		if (count == 0) {
			//It has been visited first node, [Left,Root,Right]
			//Therefore first push right child so that it comes in last
			if (node->right) {
				st.push(node->right);
				visited.push(0);
			}
			//Then push the current node
			st.push(node);
			visited.push(1); //Indicating it has been visited once

			//Now push left child so that it comes in top
			if (node->left) {
				st.push(node->left);
				visited.push(0);
			}
		}
		else {
			//It has been visited once already, therefore store the data
			ans.push_back(node->data);
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
	vector<int>ans = inOrder(node);
	printArray_1D(ans);
}
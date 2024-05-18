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

vector<int> preOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<int>ans;

	stack<TreeNode *>st;
	st.push(root);
	while (st.size() != 0) {
		//PreOrder -> PrintNode, Left, Right
		//Step 1: Print the element
		TreeNode *node = st.top();
		st.pop();
		ans.push_back(node->data);

		//Step 2: For left subtree to be executed, we will first push right child
		if (node->right) {
			st.push(node->right);
		}
		//Step 3: Push left child
		if (node->left) {
			st.push(node->left);
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
	vector<int>ans = preOrder(node);
	printArray_1D(ans);
}
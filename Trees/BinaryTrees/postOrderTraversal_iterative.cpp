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

vector<int> postOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<int>ans;

	stack<TreeNode *>st;
	st.push(root);
	while (st.size() != 0) {
		//PostOrder ->  Left, Right, PrintNode
		//Step 1: Reverse the order [PrintNode, Right, Left] : we will get reversed answer
		TreeNode *node = st.top();
		st.pop();
		ans.push_back(node->data);

		//Step 2: For right subtree to be executed, we will first push left child
		if (node->left) {
			st.push(node->left);
		}
		//Step 3: Push right child
		if (node->right) {
			st.push(node->right);
		}
	}
	reverse(ans.begin(), ans.end());
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
	vector<int>ans = postOrder(node);
	printArray_1D(ans);
}
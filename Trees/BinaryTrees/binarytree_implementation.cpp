#include <bits/stdc++.h>
using namespace std;

void printArray_1D(vector<int> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}
void printArray_2D(vector<vector<int>> &arr)
{
    for (auto it : arr)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/*
Time complexity: O(N)
Space complexity: O(N)
*/

/*-------------------Write code downwards--------------------------------------------------------------*/

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    /*
    Take Input here if needed
    */

    int x, first, second;
    cin >> x;
    cout << "Enter the root node: " << x << endl;
    queue<TreeNode *> q;
    q.push(new TreeNode(x));

    while (!q.empty())
    {
        // Step 1: Pop out the front element
        TreeNode *temp = q.front();
        q.pop();

        cout << "Enter the left child of: " << temp->data << ": " << endl;
        cin >> first;
        if (first != -1)
        {
            temp->left = new TreeNode(first);
            q.push(temp->left);
        }

        cout << "Enter the right child of: " << temp->data << ": " << endl;
        cin >> second;
        if (second != -1)
        {
            temp->right = new TreeNode(second);
            q.push(temp->right);
        }
    }
}
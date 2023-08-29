#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == 0)
        return;

    if (root->left == 0 and root->right == 0)
    {
        temp.push_back(root->val);
        sum += root->val;
        if (sum == targetSum)
            ans.push_back(temp);
        return;
    }

    temp.push_back(root->val);
    sum += root->val;

    solve(root->left, targetSum, sum, temp, ans);
    solve(root->right, targetSum, sum, temp, ans);
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}

int main()
{
    // Construct the binary tree for testing
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> result = pathSum(root, targetSum);

    // Display the results
    for (const vector<int> &path : result)
    {
        cout << "Path: ";
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
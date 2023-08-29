#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sum(TreeNode *root, int &ans)
{
    if (root == 0)
        return 0;

    int left = sum(root->left, ans);
    int right = sum(root->right, ans);

    int maxSum = max(max(root->val, root->val + left + right), max(root->val + left, root->val + right));

    ans = max(ans, maxSum);

    return max(root->val, max(root->val + left, root->val + right));
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    sum(root, ans);
    return ans;
}

void deleteTree(TreeNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;

    // Free the allocated memory for the tree nodes
    deleteTree(root);

    return 0;
}
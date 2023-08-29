#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, int targetSum, int sum, bool &ans)
{
    if (root == 0)
        return;

    if (root->left == 0 and root->right == 0)
    {
        sum += root->val;
        if (sum == targetSum)
            ans = true;
        return;
    }

    sum += root->val;

    solve(root->left, targetSum, sum, ans);
    solve(root->right, targetSum, sum, ans);
}

bool hasPathSum(TreeNode *root, int targetSum)
{

    int sum = 0;
    bool ans = false;
    solve(root, targetSum, sum, ans);
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
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    bool result = hasPathSum(root, targetSum);

    if (result)
    {
        cout << "There is a path with sum " << targetSum << "." << endl;
    }
    else
    {
        cout << "No path with sum " << targetSum << " found." << endl;
    }

    return 0;
}
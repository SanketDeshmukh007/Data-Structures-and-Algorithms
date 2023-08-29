#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// N L R
int ans = 0;
void solve(TreeNode *root, long long sum)
{
    if (root == 0)
        return;

    if (root->val == sum)
        ans++;

    solve(root->left, sum - root->val);
    solve(root->right, sum - root->val);
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == 0)
        return 0;
    solve(root, targetSum);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return ans;
}

/*
int pathSum_a(TreeNode *root, long long targetSum)
{
    if (root == 0)
        return 0;

    int count = 0;

    if (root->val == targetSum)
        count++;
    count += pathSum_a(root->left, targetSum - root->val);
    count += pathSum_a(root->right, targetSum - root->val);

    return count;
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root == 0)
        return 0;

    int count = pathSum_a(root, targetSum);
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count;
}
*/

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    int result = pathSum(root, targetSum);
    std::cout << "Number of paths with sum " << targetSum << ": " << result << std::endl;

    // TODO: Don't forget to free the allocated memory for the tree nodes

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

int solve(TreeNode *root)
{
    if (root == 0)
        return 0;

    int robThisHouse = 0, dontRobThisHouse = 0;

    // robThisHouse
    robThisHouse += root->val;
    if (root->left)
        robThisHouse += solve(root->left->left) + solve(root->left->right);
    if (root->right)
        robThisHouse += solve(root->right->left) + solve(root->right->right);

    // dontRobThisHouse
    dontRobThisHouse += solve(root->left) + solve(root->right);

    return max(robThisHouse, dontRobThisHouse);
}

int solveMem(TreeNode *root, unordered_map<TreeNode *, int> &dp)
{
    if (root == 0)
        return 0;

    if (dp.find(root) != dp.end())
        return dp[root];

    int robThisHouse = 0, dontRobThisHouse = 0;

    // robThisHouse
    robThisHouse += root->val;
    if (root->left)
        robThisHouse += solveMem(root->left->left, dp) + solveMem(root->left->right, dp);
    if (root->right)
        robThisHouse += solveMem(root->right->left, dp) + solveMem(root->right->right, dp);

    // dontRobThisHouse
    dontRobThisHouse += solveMem(root->left, dp) + solveMem(root->right, dp);

    dp[root] = max(robThisHouse, dontRobThisHouse);
    return dp[root];
}

int rob(TreeNode *root)
{
    // 1. Recursion
    // return solve(root);

    // 2. Memoization
    // TC - O(N) and SC - O(N)
    unordered_map<TreeNode *, int> dp;
    return solveMem(root, dp);
}

int main()
{
    //

    return 0;
}
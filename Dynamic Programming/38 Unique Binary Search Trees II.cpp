#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<TreeNode *> solve(int start, int end)
{
    // Base Case
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};

    vector<TreeNode *> ans;

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = solve(start, i - 1);
        vector<TreeNode *> right = solve(i + 1, end);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode *> solveMem(int start, int end, vector<vector<vector<TreeNode *>>> &dp)
{
    // Base Case
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};

    if (dp[start][end].size() != NULL)
        return dp[start][end];

    vector<TreeNode *> ans;

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = solveMem(start, i - 1, dp);
        vector<TreeNode *> right = solveMem(i + 1, end, dp);

        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    return dp[start][end] = ans;
}

vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return {};
    // Recursion
    // return solve(1,n);
    // Memoization
    vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>(NULL)));
    return solveMem(1, n, dp);
}

int main()
{
    //

    return 0;
}
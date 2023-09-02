#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);
    return root;
}
// 0-valid,1-sum,2-minval,3-maxval
int maxsum = 0;

vector<int> solve(TreeNode *root)
{
    // Base Case
    if(root == 0) return {1,0,INT_MAX,INT_MIN};
    if(root->left == 0 and root->right == 0)
    {
        maxsum = max(maxsum,root->val);
        return {1,root->val,root->val,root->val};
    }

    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);

    if(l[0] and r[0])
    {
        if(root->val > l[3] and root->val < r[2])
        {
            int mini = min(l[2],root->val);
            int maxi = max(r[3],root->val);
            int sum = l[1] + r[1] + root->val;
            maxsum = max(maxsum,sum);

            return {1,sum,mini,maxi};
        }
    }
    
    return {0,max(l[1],r[1]),0,0};
}

int maxSumBST(TreeNode* root) 
{
    solve(root);
    return maxsum;
}

int main()
{
    TreeNode *root = createTree();

    int maxSum = maxSumBST(root);
    cout << "Maximum Sum among BSTs: " << maxSum << endl;

    return 0;
}
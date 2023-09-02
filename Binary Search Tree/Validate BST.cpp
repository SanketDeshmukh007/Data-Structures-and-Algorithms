#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool valid(TreeNode *root, long int lb, long int ub)
{
    if (root == 0)
        return true;

    if (root->val > lb and root->val < ub)
    {
        bool leftAns = valid(root->left, lb, root->val);
        bool rightAns = valid(root->right, root->val, ub);
        return (leftAns and rightAns);
    }

    return false;
}

bool isValidBST(TreeNode *root)
{
    long int lb = -pow(2, 32);
    long int ub = pow(2, 32);
    return valid(root, lb, ub);
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // Uncomment the following lines to create an invalid BST
    // root->right->left = new TreeNode(2);

    bool isBST = isValidBST(root);

    if (isBST)
    {
        cout << "The given tree is a valid BST." << endl;
    }
    else
    {
        cout << "The given tree is not a valid BST." << endl;
    }

    return 0;
}
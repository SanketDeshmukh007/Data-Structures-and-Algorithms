#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == 0)
        return NULL;

    // Case 1
    if (p->val < root->val and q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    // Case 2
    if (p->val > root->val and q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    // Case 3 and 4
    return root;
}

int main()
{
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << std::endl;

    return 0;
}
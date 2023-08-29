#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{   
    if(root == NULL) return NULL;
        
    if(root->val == p->val) return p;
    if(root->val == q->val) return q;
        
    TreeNode *leftAns = lowestCommonAncestor(root->left,p,q);
    TreeNode *rightAns = lowestCommonAncestor(root->right,p,q);
        
    if(leftAns == 0 and rightAns == 0) return NULL;
    else if(leftAns != 0 and rightAns == 0) return leftAns;
    else if(leftAns == 0 and rightAns != 0) return rightAns;
    else return root;
}

int main()
{
    // Create a binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *p = root->left;
    TreeNode *q = root->right;

    // Find the lowest common ancestor
    TreeNode *lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    // Clean up memory by deallocating the tree nodes
    // (not shown in this example, but you should do it)

    return 0;
}

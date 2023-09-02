#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create(vector<int> &preorder, int &i, int bound)
{
    // Base Case
    if (i == int(preorder.size()) or preorder[i] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = create(preorder, i, root->val);
    root->right = create(preorder, i, bound);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    return create(preorder, i, INT_MAX);
}

// Function to print the inorder traversal of a BST
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main()
{
    // Sample input: preorder traversal of a BST
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Construct the BST
    TreeNode *root = bstFromPreorder(preorder);

    // Print the inorder traversal of the constructed BST
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
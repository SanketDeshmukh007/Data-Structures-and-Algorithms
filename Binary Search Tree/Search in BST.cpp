#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == 0)
        return NULL;

    if (root->val == val)
        return root;

    if (val > root->val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);
}

// Function to insert a value into a BST
TreeNode *insertBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (val > root->val)
        root->right = insertBST(root->right, val);
    else
        root->left = insertBST(root->left, val);

    return root;
}

// Function to create a sample BST
TreeNode *createBST()
{
    TreeNode *root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 6);
    insertBST(root, 9);
    return root;
}

int main()
{
    TreeNode *root = createBST();

    int target = 3;
    TreeNode *result = searchBST(root, target);

    if (result != NULL)
        cout << "Found " << target << " in the BST." << endl;
    else
        cout << target << " not found in the BST." << endl;

    return 0;
}
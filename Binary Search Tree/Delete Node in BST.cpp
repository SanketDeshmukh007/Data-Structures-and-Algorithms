#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int predecessor(TreeNode *root, int key)
{
    TreeNode *pre = NULL;
    TreeNode *curr = root;

    while (curr)
    {
        if (curr->val >= key)
            curr = curr->left;
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }
    return pre->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == 0)
        return NULL;

    if (root->val == key)
    {
        if (root->left == 0 and root->right == 0)
            return NULL;
        else if (root->left == 0 and root->right != 0)
            return root->right;
        else if (root->left != 0 and root->right == 0)
            return root->left;
        else
        {
            int pre = predecessor(root->left, key);
            root->val = pre;
            root->left = deleteNode(root->left, pre);
            return root;
        }
    }
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
        root->left = deleteNode(root->left, key);

    return root;
}

// Function to insert a node into the binary search tree
TreeNode *insert(TreeNode *root, int key)
{
    if (root == NULL)
    {
        return new TreeNode(key);
    }
    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

// Print the inorder traversal of the binary search tree
void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main()
{
    TreeNode *root = NULL;

    // Insert nodes into the binary search tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 9);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << endl;

    int keyToDelete = 5;
    root = deleteNode(root, keyToDelete);

    cout << "Inorder traversal after deleting " << keyToDelete << ": ";
    inorder(root);
    cout << endl;

    return 0;
}
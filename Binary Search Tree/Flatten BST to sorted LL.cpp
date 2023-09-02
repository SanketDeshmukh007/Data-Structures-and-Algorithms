#include <iostream>
using namespace std;

template <typename T>
struct TreeNode
{
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform an in-order traversal to flatten the tree
template <typename T>
void inorder(TreeNode<T> *root, TreeNode<T> *&prev)
{
    if (!root)
        return;

    inorder(root->left, prev);

    prev->left = nullptr;
    prev->right = root;
    prev = root;

    inorder(root->right, prev);
}

// Function to flatten a binary tree into a linked list
template <typename T>
TreeNode<T> *flatten(TreeNode<T> *root)
{
    TreeNode<T> *dummy = new TreeNode<T>(-1);
    TreeNode<T> *prev = dummy;
    inorder(root, prev);
    prev->left = nullptr;
    prev->right = nullptr;
    root = dummy->right;
    delete dummy;
    return root;
}

int main()
{
    // Create a sample binary tree
    TreeNode<int> *root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(6);
    root->right = new TreeNode<int>(12);
    root->left->left = new TreeNode<int>(2);
    root->left->right = new TreeNode<int>(8);
    root->right->left = new TreeNode<int>(11);
    root->right->right = new TreeNode<int>(15);

    // Flatten the binary tree into a linked list
    TreeNode<int> *flattened = flatten(root);

    // Print the flattened linked list
    while (flattened)
    {
        cout << flattened->val << " ";
        flattened = flattened->right;
    }

    return 0;
}

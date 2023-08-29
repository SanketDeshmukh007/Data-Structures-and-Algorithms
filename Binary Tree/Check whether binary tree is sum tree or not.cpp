#include <iostream>

using namespace std;

// Define a TreeNode structure
template <typename T>
struct TreeNode
{
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to create a sample binary tree
TreeNode<int> *createSampleTree()
{
    TreeNode<int> *root = new TreeNode<int>(20);
    root->left = new TreeNode<int>(3);
    root->right = new TreeNode<int>(7);
    root->left->left = new TreeNode<int>(1);
    root->left->right = new TreeNode<int>(2);
    root->right->left = new TreeNode<int>(4);
    root->right->right = new TreeNode<int>(3);
    return root;
}

// Function to deallocate memory for the tree nodes
void deleteTree(TreeNode<int> *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

bool flag = true;

int sum(TreeNode<int> *root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return root->val;
    if (flag == false)
        return 0;

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);

    if (root->val != leftsum + rightsum)
        flag = false;

    return root->val + leftsum + rightsum;
}

bool isSumTree(TreeNode<int> *root)
{
    sum(root);
    return flag;
}

int main()
{
    TreeNode<int> *root = createSampleTree();

    // Check if the tree is a Sum Tree
    bool isSumTreeResult = isSumTree(root);

    if (isSumTreeResult)
    {
        cout << "The given tree is a Sum Tree." << endl;
    }
    else
    {
        cout << "The given tree is not a Sum Tree." << endl;
    }

    // Clean up the memory by deallocating the tree nodes
    deleteTree(root);

    return 0;
}

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

bool mirror(TreeNode *left, TreeNode *right)
{
    if (left == 0 or right == 0)
        return left == right;

    return ((left->val == right->val) and mirror(left->left, right->right) and mirror(left->right, right->left));
}

bool isSymmetric(TreeNode *root)
{
    if (root == 0)
        return true;

    return mirror(root->left, root->right);
}

// Function to create a sample binary tree
TreeNode *createSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}

int main()
{
    TreeNode *root = createSampleTree();

    bool isSymmetricResult = isSymmetric(root);

    if (isSymmetricResult)
    {
        cout << "The tree is symmetric." << endl;
    }
    else
    {
        cout << "The tree is not symmetric." << endl;
    }

    // Clean up memory (not shown in this example, but you should deallocate the nodes)

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct TreeNode
{
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

void Left(TreeNode<int> *root, vector<int> &ans)
{
    if (root == 0)
        return;
    if (root->left == 0 and root->right == 0)
        return;

    ans.push_back(root->data);

    if (root->left)
        Left(root->left, ans);
    else
        Left(root->right, ans);
}

void leaf(TreeNode<int> *root, vector<int> &ans)
{
    if (root == 0)
        return;
    if (root->left == 0 and root->right == 0)
    {
        ans.push_back(root->data);
        return;
    }

    if (root->left)
        leaf(root->left, ans);
    if (root->right)
        leaf(root->right, ans);
}

void Right(TreeNode<int> *root, vector<int> &ans)
{
    if (root == 0)
        return;
    if (root->left == 0 and root->right == 0)
        return;

    if (root->right)
        Right(root->right, ans);
    else
        Right(root->left, ans);

    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    // A
    Left(root->left, ans);
    // B
    leaf(root, ans);
    // C
    Right(root->right, ans);

    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);

    // Call the traverseBoundary function
    vector<int> result = traverseBoundary(root);

    // Print the result
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorder;
void Inorder(TreeNode *root)
{
    if (root == 0)
        return;

    Inorder(root->left);
    inorder.push_back(root->val);
    Inorder(root->right);
}

bool findTarget(TreeNode *root, int k)
{
    Inorder(root);

    int start = 0, end = inorder.size() - 1;

    while (start < end)
    {
        int sum = inorder[start] + inorder[end];

        if (sum == k)
            return true;

        if (sum > k)
            end--;
        else
            start++;
    }
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int target = 9;

    bool found = findTarget(root, target);

    if (found)
    cout << "There exist two elements in the BST that sum up to " << target << "." << endl;
    else
    cout << "No such elements exist in the BST that sum up to " << target << "." << endl;

    return 0;
}
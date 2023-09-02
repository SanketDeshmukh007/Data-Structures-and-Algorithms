#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int ans = -1;
void inorder(TreeNode *root, int &k)
{
    if (root == 0)
        return;

    inorder(root->left, k);
    k--;
    if (k == 0)
    {
        ans = root->val;
        return;
    }
    inorder(root->right, k);
}

int kthSmallest(TreeNode *root, int k)
{
    inorder(root, k);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 3;
    int kthSmallestValue = kthSmallest(root, k);

    cout << "The " << k << "th smallest element is: " << kthSmallestValue << std::endl;

    return 0;
}
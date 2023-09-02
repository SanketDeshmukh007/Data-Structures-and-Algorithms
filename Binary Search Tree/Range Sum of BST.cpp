#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode *root, int low, int high, int &ans)
{
    if (!root)
        return;

    if (root->val >= low and root->val <= high)
        ans += root->val;

    solve(root->left, low, high, ans);
    solve(root->right, low, high, ans);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    solve(root, low, high, ans);
    return ans;
}

// Function to insert a node into a BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == nullptr) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

int main() {
    // Create a binary search tree
    TreeNode* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    int low = 7;
    int high = 15;

    // Calculate the sum of values within the range [low, high]
    int sum = rangeSumBST(root, low, high);

    cout << "Sum of values within the range [" << low << ", " << high << "] is: " << sum << endl;

    return 0;
}
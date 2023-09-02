#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> v;
void inorder(TreeNode *root)
{
    if (root == 0)
        return;

    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

TreeNode *create(int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(v[mid]);
    root->left = create(s, mid - 1);
    root->right = create(mid + 1, e);
    return root;
}

TreeNode *balanceBST(TreeNode *root)
{
    inorder(root);
    return create(0, v.size() - 1);
}

// Function to insert a node into a BST
TreeNode* insert(TreeNode* root, int key) {
    if (root == NULL) {
        return new TreeNode(key);
    }
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else if (key > root->val) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to build an unbalanced BST from an array
TreeNode* buildUnbalancedBST(vector<int>& arr) {
    TreeNode* root = nullptr;
    for (int key : arr) {
        root = insert(root, key);
    }
    return root;
}

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    // Input array to construct an unbalanced BST
    vector<int> unbalancedBST = {1, 2, 3, 4, 5, 6, 7}; // Modify as needed

    // Build an unbalanced BST from the input array
    TreeNode* root = buildUnbalancedBST(unbalancedBST);

    // Balance the BST using the balanceBST function
    TreeNode* balancedRoot = balanceBST(root);

    v.clear();
    inorder(balancedRoot);
    printVector(v);

    return 0;
}
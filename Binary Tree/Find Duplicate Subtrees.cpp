#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<TreeNode *> ans;
unordered_map<string, int> m;

string preorder(TreeNode *root)
{
    if (root == 0)
        return "N";

    string curr = to_string(root->val);
    string l = preorder(root->left);
    string r = preorder(root->right);
    string total = curr + "," + l + "," + r;

    m[total]++;

    if (m[total] == 2)
        ans.push_back(root);

    return total;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    preorder(root);
    return ans;
}

// Helper function to create the specified binary tree
TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = nullptr; // null node
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = nullptr;  // null node
    root->right->left->right = nullptr; // null node
    root->right->right->left = nullptr; // null node
    root->right->right->right = new TreeNode(4);
    return root;
}

// Recursive function to deallocate memory
void cleanUpMemory(TreeNode *root)
{
    if (root == nullptr)
        return;

    cleanUpMemory(root->left);
    cleanUpMemory(root->right);

    delete root;
}

// Recursive function to print the values of a subtree
void printSubtreeValues(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->val << " ";

    printSubtreeValues(root->left);
    printSubtreeValues(root->right);
}

int main()
{
    TreeNode *root = createTree();
    vector<TreeNode *> duplicates = findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees:" << endl;
    for (TreeNode *subtree : duplicates)
    {
        cout << "Subtree values: ";
        printSubtreeValues(subtree); // Print subtree values
        cout << endl;
    }

    // Clean up memory by deleting nodes
    cleanUpMemory(root);

    return 0;
}
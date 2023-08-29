#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &m)
{
    // Base Case
    if (preIndex >= int(preorder.size()) or inorderStart > inorderEnd)
        return NULL;

    int element = preorder[preIndex++];
    int pos = m[element];

    TreeNode *root = new TreeNode(element);
    root->left = solve(preorder, inorder, preIndex, inorderStart, pos - 1, m);
    root->right = solve(preorder, inorder, preIndex, pos + 1, inorderEnd, m);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;
    int inorderStart = 0;
    int inorderEnd = inorder.size() - 1;
    unordered_map<int, int> m;
    for (int i = 0; i < int(inorder.size()); i++)
    {
        m[inorder[i]] = i;
    }
    TreeNode *root = solve(preorder, inorder, preIndex, inorderStart, inorderEnd, m);
    return root;
}

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            cout << temp->val << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTree(preorder, inorder);
    levelOrderTraversal(root);

    return 0;
}
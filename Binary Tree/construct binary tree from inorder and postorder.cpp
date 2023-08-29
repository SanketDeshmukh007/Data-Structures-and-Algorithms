#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &m)
{
    // Base Case
    if (postIndex < 0 or inorderStart > inorderEnd)
        return NULL;

    int element = postorder[postIndex--];
    int pos = m[element];

    TreeNode *root = new TreeNode(element);
    root->right = solve(inorder, postorder, postIndex, pos + 1, inorderEnd, m);
    root->left = solve(inorder, postorder, postIndex, inorderStart, pos - 1, m);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{

    int postIndex = postorder.size() - 1;
    int inorderStart = 0;
    int inorderEnd = inorder.size() - 1;
    unordered_map<int, int> m;
    for (int i = 0; i < int(inorder.size()); i++)
    {
        m[inorder[i]] = i;
    }
    TreeNode *root = solve(inorder, postorder, postIndex, inorderStart, inorderEnd, m);
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
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode *root = buildTree(inorder, postorder);
    levelOrderTraversal(root);

    return 0;
}
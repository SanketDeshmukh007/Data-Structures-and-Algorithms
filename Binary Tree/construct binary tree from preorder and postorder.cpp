#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int preIndex = 0, postIndex = 0;
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    TreeNode *root = new TreeNode(preorder[preIndex++]);

    if (root->val != postorder[postIndex])
        root->left = constructFromPrePost(preorder, postorder);
    if (root->val != postorder[postIndex])
        root->right = constructFromPrePost(preorder, postorder);

    postIndex++;

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
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};

    TreeNode *root = constructFromPrePost(preorder, postorder);
    levelOrderTraversal(root);

    return 0;
}
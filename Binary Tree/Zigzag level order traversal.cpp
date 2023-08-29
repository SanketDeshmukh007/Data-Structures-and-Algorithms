#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == 0)
        return ans;

    queue<TreeNode *> q;
    q.push(root);
    int idx = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            level.push_back(temp->val);

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        if (idx & 1)
            reverse(level.begin(), level.end());

        ans.push_back(level);
        idx++;
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the zigzagLevelOrder function
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the results
    for (const vector<int> &level : result)
    {
        cout << "[";
        for (int val : level)
        {
            cout << val;
            if (&val != &level.back())
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
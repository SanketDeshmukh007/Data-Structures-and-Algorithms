#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            // Step A
            TreeNode *temp = q.front();
            // Step B
            q.pop();

            // Step C
            level.push_back(temp->val);

            // Step D
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        ans.push_back(level);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

// Function to create a binary tree from an array representation
TreeNode *createTreeFromArray(const vector<int> &arr, int index)
{
    if (index >= int(arr.size()) || arr[index] == -1)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(arr[index]);
    root->left = createTreeFromArray(arr, 2 * index + 1);
    root->right = createTreeFromArray(arr, 2 * index + 2);

    return root;
}

int main()
{
    vector<int> arr = {3, 9, 20, -1, -1, 15, 7}; // Example array representation of a binary tree
    TreeNode *root = createTreeFromArray(arr, 0);

    vector<vector<int>> result = levelOrder(root);

    // Printing the level order traversal
    for (const vector<int> &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

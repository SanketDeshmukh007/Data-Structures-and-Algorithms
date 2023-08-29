#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q; // Node , [row,col]
    q.push({root, {0, 0}});
    map<int, map<int, multiset<int>>> m; // col --> {row : [x,y,x,...]}

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *temp = front.first;
        auto coordinates = front.second;
        int row = coordinates.first;
        int col = coordinates.second;
        m[col][row].insert(temp->val);

        if (temp->left)
            q.push({temp->left, {row + 1, col - 1}});
        if (temp->right)
            q.push({temp->right, {row + 1, col + 1}});
    }

    // store final result into ans
    for (auto x : m)
    {
        vector<int> temp;
        for (auto y : x.second)
            for (auto z : y.second)
                temp.push_back(z);
        ans.push_back(temp);
    }
    return ans;
}

void deleteTree(TreeNode *root)
{
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Call the verticalTraversal function and get the result
    vector<vector<int>> result = verticalTraversal(root);

    // Display the result
    for (const auto &col : result)
    {
        for (int val : col)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the dynamically allocated memory
    deleteTree(root);

    return 0;
}
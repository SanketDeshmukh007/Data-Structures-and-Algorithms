#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
};

bool isCompleteTree(TreeNode *root)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    queue<TreeNode *> q;
    q.push(root);
    int cnt = 0;
    vector<int> v;
    int j = 1;
    while (!q.empty())
    {
        int size = q.size();
        cnt += size;
        // cout << cnt << endl;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
                v.push_back(++j);
            }
            else
                ++j;
            if (temp->right)
            {
                q.push(temp->right);
                v.push_back(++j);
            }
            else
                ++j;
        }
    }
    // cout << cnt << " " << v[v.size()-1] << endl;
    if (cnt == 1)
        return true;
    if (cnt == v[v.size() - 1])
        return true;

    return false;
}

int main()
{
    //

    return 0;
}
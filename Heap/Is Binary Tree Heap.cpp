#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool complete(struct Node *root)
{
    if (root == 0)
        return true;
    queue<Node *> q;
    q.push(root);
    int count = 0;
    vector<int> v;
    int j = 1;
    while (!q.empty())
    {
        int size = q.size();
        count += size;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
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
    return v[v.size() - 1] == count;
}

pair<bool, int> solve(struct Node *root)
{
    if (root == 0)
        return {true, INT_MIN};
    if (root->left == 0 and root->right == 0)
        return {true, root->data};

    pair<bool, int> l = solve(root->left);
    pair<bool, int> r = solve(root->right);

    if ((l.first == true and r.first == true) and root->data > l.second and root->data > r.second)
        return {true, root->data};

    return {false, INT_MAX};
}

bool isHeap(struct Node *tree)
{
    bool ans1 = complete(tree);

    pair<bool, int> ans2 = solve(tree);

    return ans1 and ans2.first;
}

int main()
{
    //

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node *root)
{
    vector<int> ans;
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *temp = p.first;
        int hd = p.second;

        if (m.find(hd) == m.end())
        {
            m[hd] = temp->data;
        }

        if (temp->left)
            q.push({temp->left, hd - 1});
        if (temp->right)
            q.push({temp->right, hd + 1});
    }

    for (auto x : m)
        ans.push_back(x.second);

    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    // Call the topView function and print the result
    vector<int> result = topView(root);
    cout << "Top View: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> diagonal(Node *root)
{
    vector<int> ans;

    if (root == 0)
        return ans;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp)
        {
            if (temp->left)
                q.push(temp->left);

            ans.push_back(temp->data);

            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    // Call the diagonal function
    vector<int> result = diagonal(root);

    // Print the results
    cout << "[";
    for (int val : result)
    {
        cout << val;
        if (&val != &result.back())
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
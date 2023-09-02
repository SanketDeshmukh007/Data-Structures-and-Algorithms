#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void solve(Node *root, unordered_map<int, bool> &m, bool &ans)
{
    if (root == 0)
        return;

    m[root->data] = true;
    if (root->left == 0 and root->right == 0)
    {
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;

        if (m[xp1] and m[xm1])
        {
            ans = true;
            return;
        }
    }

    solve(root->left, m, ans);
    solve(root->right, m, ans);
}

bool isDeadEnd(Node *root)
{
    bool ans = false;
    unordered_map<int, bool> m; // visited
    solve(root, m, ans);
    return ans;
}

// Function to insert a node into a BST
Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

// Your solve function and isDeadEnd function here...

int main()
{
    // Create a binary search tree
    Node *root = nullptr;
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 9);

    // Check if the BST has a dead end
    bool result = isDeadEnd(root);

    if (result)
    {
        cout << "The BST has a dead end." << endl;
    }
    else
    {
        cout << "The BST does not have a dead end." << endl;
    }

    return 0;
}
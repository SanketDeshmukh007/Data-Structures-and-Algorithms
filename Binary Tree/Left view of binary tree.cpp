#include <bits/stdc++.h>
using namespace std;

// Define the Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Utility function to construct a sample binary tree
Node *constructTree()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void view(Node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
        return;

    if (level == int(ans.size()))
        ans.push_back(root->data);

    view(root->left, level + 1, ans);
    view(root->right, level + 1, ans);
}

// Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level = 0;
    view(root, level, ans);
    return ans;
}

int main()
{
    Node *root = constructTree();

    // Call the leftView function and print the result
    vector<int> result = leftView(root);
    cout << "Left View: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

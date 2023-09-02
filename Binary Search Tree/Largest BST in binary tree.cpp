#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<int> solve(Node *root)
{
    if (root == 0)
        return {1, 0, INT_MAX, INT_MIN};
    if (root->left == 0 and root->right == 0)
        return {1, 1, root->data, root->data};

    vector<int> l = solve(root->left);
    vector<int> r = solve(root->right);

    if (l[0] and r[0])
    {
        if (root->data > l[3] and root->data < r[2])
        {
            int mini = l[2];
            int maxi = r[3];

            if (mini == INT_MAX)
                mini = root->data;
            if (maxi == INT_MIN)
                maxi = root->data;

            return {1, l[1] + r[1] + 1, mini, maxi};
        }
    }

    return {0, max(l[1], r[1]), 0, 0};
}

int largestBst(Node *root)
{
    vector<int> ans = solve(root);
    return ans[1];
}

int main()
{
    // Create a sample binary tree
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    // Node *root = new Node(6);
    // root->left = new Node(6);
    // root->left->right = new Node(2);
    // root->right = new Node(3);
    // root->right->left = new Node(9);
    // root->right->right = new Node(3);
    // root->right->right->left = new Node(8);
    // root->right->right->right = new Node(8);
    // root->right->right->left->left = new Node(2);

    int largest = largestBst(root);
    cout << "Largest BST length: " << largest << endl;

    return 0;
}
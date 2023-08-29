#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

pair<int, int> solve(Node *root)
{
    if (root == 0)
        return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    int sum = root->data;

    if (left.first == right.first)
        sum += max(left.second, right.second);
    else if (left.first > right.first)
        sum += left.second;
    else
        sum += right.second;

    return {max(left.first, right.first) + 1, sum};
}

int sumOfLongRootToLeafPath(Node *root)
{
    pair<int, int> ans = solve(root);
    return ans.second;
}

void cleanUpMemory(Node *root)
{
    if (root == nullptr)
        return;

    cleanUpMemory(root->left);
    cleanUpMemory(root->right);

    delete root;
}

int main()
{
    // Create the binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call the sumOfLongRootToLeafPath function
    int result = sumOfLongRootToLeafPath(root);
    cout << "Sum of Longest Root-to-Leaf Path: " << result << endl;

    // Clean up memory by deleting nodes
    cleanUpMemory(root);

    return 0;
}
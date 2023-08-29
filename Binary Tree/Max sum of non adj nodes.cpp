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

    pair<int, int> ans;

    ans.first = root->data + left.second + right.second;                        // include
    ans.second = max(left.first, left.second) + max(right.first, right.second); // exclude

    return ans;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
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

    // Call the getMaxSum function
    int maxSum = getMaxSum(root);
    cout << "Maximum Sum: " << maxSum << endl;

    // Clean up memory by deleting nodes
    cleanUpMemory(root);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a sample binary search tree
Node *createBST()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    return root;
}

int minValue(Node *root)
{
    if (root == 0)
        return -1;
    if (root->left == 0)
        return root->data;

    while (root->left)
        root = root->left;

    return root->data;
}

int maxValue(Node *root)
{
    if (root == 0)
        return -1;
    if (root->right == 0)
        return root->data;

    while (root->right)
        root = root->right;

    return root->data;
}

int main()
{
    Node *root = createBST();

    int minVal = minValue(root);
    int maxVal = maxValue(root);

    if (minVal != -1)
        cout << "The minimum value in the BST is: " << minVal << endl;
    else
        cout << "The BST is empty." << endl;
    if (maxVal != -1)
        cout << "The maximum value in the BST is: " << maxVal << endl;
    else
        cout << "The BST is empty." << endl;

    return 0;
}
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

Node *buildTree()
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;

    // Base Case
    if (data == -1)
        return NULL;

    // Step A : Create Node
    Node *root = new Node(data);
    // Step B : Left Child
    cout << "Enter the data for left part of " << data << " node" << endl;
    root->left = buildTree();
    // Step C : Right Child
    cout << "Enter the data for right part of " << data << " node" << endl;
    root->right = buildTree();

    return root;
}

void preorderTraversal(Node *root)
{
    if(root == NULL)
    return;

    // NLR
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// 90 20 11 -1 -1 13 -1 -1 50 -1 -1

int main()
{
    Node *root = NULL;

    root = buildTree();

    preorderTraversal(root);

    return 0;
}

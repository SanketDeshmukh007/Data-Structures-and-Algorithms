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

void convert(Node *root, Node *&head)
{
    if (root == 0)
        return;

    convert(root->right, head);

    root->right = head;
    if (head != 0)
        head->left = root;
    head = root;

    convert(root->left, head);
}

Node *bstTOdll(Node *root)
{
    Node *head = NULL;
    convert(root, head);
    return head;
}

// Function to print the DLL
void printDll(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main()
{
    // Create a simple Binary Search Tree
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Convert BST to DLL
    Node *head = bstTOdll(root);

    // Print the DLL
    printDll(head);

    return 0;
}
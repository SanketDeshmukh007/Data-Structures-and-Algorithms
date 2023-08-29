#include <iostream>

using namespace std;

// Define a binary tree node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to create a sample binary tree
Node *createSampleTree()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-2);
    root->right->left = new Node(3);
    root->right->right = new Node(1);
    return root;
}

// Function to print the binary tree (inorder traversal)
void printTree(Node *root)
{
    if (root == nullptr)
        return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

// Function to convert a binary tree to a Sum Tree
int sum(Node *&root)
{
    if (root == 0)
        return 0;

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    int x = root->data;

    root->data = leftsum + rightsum;

    return leftsum + rightsum + x;
}

void toSumTree(Node *node)
{
    sum(node);
}

int main()
{
    Node *root = createSampleTree();

    cout << "Original Tree (Inorder Traversal): ";
    printTree(root);
    cout << endl;

    // Convert the tree to a Sum Tree
    toSumTree(root);

    cout << "Sum Tree (Inorder Traversal): ";
    printTree(root);
    cout << endl;

    // Clean up memory (not shown in this example, but you should deallocate the nodes)

    return 0;
}

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

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        // Step A
        Node *temp = q.front();
        // Step B
        q.pop();
        // Step C
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            // Step D
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
// 90 20 11 -1 -1 13 -1 -1 50 -1 -1
int main()
{
    Node *root = NULL;

    root = buildTree();

    // cout << root->data << endl;
    levelOrderTraversal(root);

    return 0;
}
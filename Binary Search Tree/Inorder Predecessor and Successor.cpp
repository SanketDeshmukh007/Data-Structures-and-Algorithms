#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k) : key(k), left(NULL), right(NULL) {}
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    suc = NULL;
    pre = NULL;

    // 1. Predecessor
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->key >= key)
        {
            curr = curr->left;
        }
        else
        {
            pre = curr;
            curr = curr->right;
        }
    }

    // 2. Successor
    curr = root;
    while (curr != NULL)
    {
        if (curr->key <= key)
        {
            curr = curr->right;
        }
        else
        {
            suc = curr;
            curr = curr->left;
        }
    }
    
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int key = 55;
    Node *pre = NULL;
    Node *suc = NULL;

    findPreSuc(root, pre, suc, key);

    if (pre)
        cout << "Predecessor: " << pre->key << endl;
    else
        cout << "No Predecessor" << endl;

    if (suc)
        cout << "Successor: " << suc->key << endl;
    else
        cout << "No Successor" << endl;

    return 0;
}

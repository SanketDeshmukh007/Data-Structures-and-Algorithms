#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

vector<int> v;
void inorder(Node *root)
{
    if (root == 0)
        return;

    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}
int i = 0;
void postorder(Node *&root)
{
    if (root == 0)
        return;

    postorder(root->left);
    postorder(root->right);
    root->data = v[i++];
}
void convertToMaxHeapUtil(Node *root)
{
    v.clear();
    inorder(root);
    postorder(root);
}

int main()
{
    //

    return 0;
}
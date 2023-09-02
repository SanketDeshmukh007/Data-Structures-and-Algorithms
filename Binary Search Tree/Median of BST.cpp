#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> v;
void inorder(struct Node *root)
{
    if (root == 0)
        return;

    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}

float findMedian(struct Node *root)
{
    v.clear();
    inorder(root);
    int n = v.size();
    if (n & 1)
    {
        return float(v[n / 2]);
    }

    // cout << v[n/2] << " " << v[n/2 - 1] << endl;

    float avg = float(v[n / 2] + v[(n / 2) - 1]) / 2;
    // cout << avg << endl;
    return avg;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    float median = findMedian(root);
    cout << "Median of the BST is: " << median << endl;

    return 0;
}
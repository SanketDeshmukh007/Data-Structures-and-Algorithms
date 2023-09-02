#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> merge(Node *root1, Node *root2)
{
    vector<int> a;
    vector<int> b;
    inorder(root1, a);
    inorder(root2, b);
    vector<int> ans;

    int i = 0, j = 0, m = a.size(), n = b.size();
    while (i < m and j < n)
    {
        if (a[i] <= b[j])
            ans.push_back(a[i++]);
        else
            ans.push_back(b[j++]);
    }
    while (i < m)
        ans.push_back(a[i++]);
    while (j < n)
        ans.push_back(b[j++]);

    return ans;
}

int main()
{
    // Create two sample binary trees
    Node *root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    // Merge the sorted vectors
    vector<int> merged = merge(root1, root2);

    // Print the merged vector
    cout << "Merged Vector: ";
    for (int num : merged)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void inorder(Node *root, vector<int> &ans)
{
    if (root == 0)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

int countPairs(Node *root1, Node *root2, int x)
{
    vector<int> i1;
    vector<int> i2;
    inorder(root1, i1);
    inorder(root2, i2);

    int n = i1.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int num = x - i1[i];
        int start = 0, end = i2.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (num == i2[mid])
                count++;

            if (num > i2[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
    }
    return count;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return new Node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to build a BST from an array
Node *buildBST(vector<int> &arr)
{
    Node *root = nullptr;
    for (int key : arr)
    {
        root = insert(root, key);
    }
    return root;
}

int main()
{
    vector<int> arr1 = {5, 3, 7, 2, 4, 6, 8};     // Modify as needed
    vector<int> arr2 = {10, 5, 15, 3, 7, 12, 18}; // Modify as needed

    // Build BSTs from input arrays
    Node *root1 = buildBST(arr1);
    Node *root2 = buildBST(arr2);

    // Target sum
    int x = 10; // Modify as needed

    // Call the countPairs function
    int count = countPairs(root1, root2, x);

    // Output the result
    cout << "Number of pairs with a sum of " << x << " is: " << count << endl;

    return 0;
}
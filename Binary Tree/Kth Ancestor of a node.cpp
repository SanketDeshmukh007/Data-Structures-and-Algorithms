#include <iostream>

using namespace std;

template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

bool solve(BinaryTreeNode<int> *root, int targetNodeVal, int &k, int &ans)
{
    if(root == 0) return false;
    if(root->data == targetNodeVal) return true;

    bool left = solve(root->left,targetNodeVal,k,ans);
    bool right = solve(root->right,targetNodeVal,k,ans);

    if(left == true or right == true) k--;
    
    if(k == 0)
    {
        ans = root->data;
        k = -1;
    }

    return (left or right);
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k)
{
    int ans = -1;
    solve(root, targetNodeVal, k, ans);
    return ans;
}

int main()
{
    // Create a binary tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);

    int targetNodeVal = 5;
    int k = 2;

    // Find the kth ancestor
    int kthAncestor = findKthAncestor(root, targetNodeVal, k);

    if (kthAncestor != -1)
    {
        cout << "The " << k << "th ancestor of node " << targetNodeVal << " is: " << kthAncestor << endl;
    }
    else
    {
        cout << "No " << k << "th ancestor found for the given target node." << endl;
    }

    // Clean up memory by deallocating the tree nodes
    // (not shown in this example, but you should do it)

    return 0;
}

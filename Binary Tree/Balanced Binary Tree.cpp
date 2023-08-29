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
// O(N)
bool ans = true;
int height(Node *root)
{
    if (root == 0)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (ans == true and (abs(lh - rh) > 1))
        ans = false;

    return max(lh, rh) + 1;
}

bool isBalanced(Node *root)
{
    height(root);
    return ans;
}

/* O(N*2)
int height(Node *root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

bool isBalanced(Node *root)
{
    if(root == NULL)
    return true;

    int left = height(root->left);
    int right = height(root->right);
    int diff = abs(left - right);
    bool ans1 = (diff <= 1);

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    if(ans1 and leftAns and rightAns) return true;
    else return false;
}
*/
// 90 20 11 -1 -1 13 -1 -1 50 -1 -1
int main()
{
    Node *root = NULL;

    root = buildTree();

    // cout << root->data << endl;
    levelOrderTraversal(root);
    cout << endl
         << "Tree is balanced : " << isBalanced(root) << endl;

    return 0;
}
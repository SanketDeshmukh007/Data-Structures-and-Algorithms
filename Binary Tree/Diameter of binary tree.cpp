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
/* Method 1 : O(N*2) O(1)
int height(Node *root)
{
    if(root == NULL)
    return 0;

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}

int diameter(Node *root)
{
    if(root == NULL)
    return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right); // + 1

    int ans = max(op1,max(op2,op3));
    return ans;
}
*/
// Method 2 : O(N)
int d = 0;
int height(Node *root)
{
    if (root == 0)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int currd = lh + rh;
    d = max(currd, d);

    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(Node *root)
{
    height(root);
    return d;
}
// 90 20 11 -1 -1 13 -1 -1 50 -1 -1
int main()
{
    Node *root = NULL;

    root = buildTree();

    // cout << root->data << endl;
    levelOrderTraversal(root);
    cout << endl
         << "Diameter of tree is " << diameterOfBinaryTree(root) << endl;

    return 0;
}
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

Node *CreateTreeFromInorder(vector<int> inorder, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    int ele = inorder[mid];

    Node *root = new Node(ele);

    root->left = CreateTreeFromInorder(inorder, start, mid - 1);
    root->right = CreateTreeFromInorder(inorder, mid + 1, end);

    return root;
}

void levelOrderTraversal(Node *root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        cout << endl;
    }
}

int main()
{
    vector<int> inorder = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int start = 0;
    int end = 8;

    Node *root = CreateTreeFromInorder(inorder, start, end);
    levelOrderTraversal(root);

    return 0;
}
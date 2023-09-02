#include<bits/stdc++.h>
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

Node* insertIntoBst(Node* &root,int data)
{
    if(root == 0)
    {
        root = new Node(data);
        return root;
    }
    
    if(data > root->data)
    root->right = insertIntoBst(root->right,data);
    else 
    root->left = insertIntoBst(root->left,data);

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cout << "Enter data" << endl;
    cin >> data;

    while(data != -1)
    {
        insertIntoBst(root,data);
        cout << "Enter data" << endl;
        cin >> data;
    }
}

void preorder(Node *root)
{
    if(root == 0)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if(root == 0)
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if(root == 0)
    return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
// 10 20 5 11 17 2 4 8 6 25 15 -1
int main()
{
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal" << endl;
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal" << endl;
    postorder(root);
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *find(Node *root, int target, unordered_map<Node *, Node *> &m)
{
    queue<Node *> q;
    q.push(root);
    m[root] = NULL;
    Node *targetNode;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->data == target)
            targetNode = temp;

        if (temp->left)
        {
            m[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            m[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return targetNode;
}

int burnTree(Node *target, unordered_map<Node *, Node *> m)
{
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool relative = false;

        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left and visited[temp->left] == false)
            {
                q.push(temp->left);
                visited[temp->left] = true;
                relative = true;
            }
            if (temp->right and visited[temp->right] == false)
            {
                q.push(temp->right);
                visited[temp->right] = true;
                relative = true;
            }
            if (m[temp] and visited[m[temp]] == false)
            {
                q.push(m[temp]);
                visited[m[temp]] = true;
                relative = true;
            }
        }
        if (relative)
            time++;
    }
    return time;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> m; // Node to Parent node mapping
    Node *targetNode = find(root, target, m);
    return burnTree(targetNode, m);
}

void cleanUpMemory(Node *root)
{
    if (root == nullptr)
        return;

    cleanUpMemory(root->left);
    cleanUpMemory(root->right);

    delete root;
}

int main()
{
    // Create the binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->right = new Node(9);
    root->right->right->right->right = new Node(10);

    // Call the sumOfLongRootToLeafPath function
    int result = minTime(root,8);
    cout << "The minimum time required to burn tree is: " << result << " seconds" << endl;

    // Clean up memory by deleting nodes
    cleanUpMemory(root);

    return 0;
}
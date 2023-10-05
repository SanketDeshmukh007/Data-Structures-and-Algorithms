#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{

    unordered_map<int, bool> m;

    Node *temp = head2;
    while (temp != 0)
    {
        m[temp->data] = true;
        temp = temp->next;
    }

    Node *head = NULL;
    Node *tail = NULL;

    temp = head1;

    while (temp != 0)
    {
        if (m[temp->data] == true and head == 0)
        {
            head = tail = new Node(temp->data);
        }
        else if (m[temp->data] == true)
        {
            tail->next = new Node(temp->data);
            tail = tail->next;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    //

    return 0;
}
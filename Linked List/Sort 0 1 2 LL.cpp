#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtTail(Node *curr, Node *&tail)
{
    tail->next = curr;
    tail = curr;
}

Node *sortList(Node *head)
{
    if (head == 0)
        return head;

    Node *zerohead = new Node(-1);
    Node *zerotail = zerohead;

    Node *onehead = new Node(-1);
    Node *onetail = onehead;

    Node *twohead = new Node(-1);
    Node *twotail = twohead;

    Node *curr = head;
    while (curr != 0)
    {
        int val = curr->data;
        if (val == 0)
        {
            InsertAtTail(curr, zerotail);
        }
        else if (val == 1)
        {
            InsertAtTail(curr, onetail);
        }
        else if (val == 2)
        {
            InsertAtTail(curr, twotail);
        }
        curr = curr->next;
    }

    // Merging
    if (onehead->next == 0)
    {
        zerotail->next = twohead->next;
    }
    else
    {
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    twotail->next = 0;
    head = zerohead->next;
    // delete zerohead, onehead, twohead, zerotail, onetail, twotail;

    return head;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *first = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(0);
    Node *fourth = new Node(0);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    print(head);

    head = sortList(head);
    print(head);

    return 0;
}

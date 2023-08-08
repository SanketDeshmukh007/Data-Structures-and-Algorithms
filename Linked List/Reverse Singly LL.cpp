#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head, Node *&tail)
{
    Node *temp = head;
    tail = temp;
    while (temp != 0)
    {
        cout << temp->data << " ";
        tail = temp;
        temp = temp->next;
    }
    cout << endl
         << "...The End..." << endl;
}

// 1. Insert at begining
void insertAtBeg(int data, Node *&head, Node *&tail)
{
    Node *newnode = new Node(data);

    if (head == NULL)
    {
        head = tail = newnode;
    }
    newnode->next = head;
    head = newnode;
}

int findLen(Node *&head);
void insertAtTail(int data, Node *&tail);

// 2. Insert at position
void insertAtPos(int data, int pos, Node *&head, Node *&tail)
{
    if (pos == 1)
    {
        insertAtBeg(data, head, tail);
        return;
    }

    int len = findLen(head);
    if (pos == len + 1)
    {
        insertAtTail(data, tail);
        return;
    }

    Node *temp = head;
    int i = 1;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
}

// 3. Insert at end
void insertAtEnd(int data, Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newnode = new Node(data);
    temp->next = newnode;
}

void insertAtTail(int data, Node *&tail)
{
    Node *newnode = new Node(data);

    if (tail == NULL)
        tail = newnode;

    tail->next = newnode;
    tail = newnode;
}

int findLen(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *reverseList(Node *head)
{
    if (head == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;

    while (curr != 0)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int main()
{
    // Node *head = new Node();
    Node *head = new Node(20);
    Node *tail = new Node();
    print(head, tail);
    insertAtBeg(10, head, tail);
    print(head, tail);
    insertAtEnd(30, head);
    print(head, tail);
    insertAtEnd(50, head);
    print(head, tail);
    insertAtEnd(60, head);
    print(head, tail);
    insertAtPos(40, 4, head, tail);
    print(head, tail);
    insertAtPos(5, 1, head, tail);
    print(head, tail);
    insertAtPos(70, 8, head, tail);
    print(head, tail);
    insertAtTail(80, tail);
    print(head, tail);
    insertAtPos(90, 10, head, tail);
    print(head, tail);

    cout << "After Reversing" << endl;
    head = reverseList(head);
    print(head,tail);

    return 0;
}
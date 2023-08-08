#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *prev;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while(temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << "End of Doubly LL" << endl;
}

int length(Node *&head)
{
    int count = 0;
    Node *temp = head;
    while(temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 1. Insert at Begining
void insertAtBeg(int data,Node *&head,Node *&tail)
{
    Node *newnode = new Node(data);

    if(head == NULL and tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

// 2. Insert at Tail
void insertAtTail(int data,Node *&head,Node *&tail)
{
    Node *newnode = new Node(data);

    if(head == NULL and tail == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// 3. Insert at Pos
void insertAtPos(int pos,int data,Node *&head,Node *&tail)
{
    int len = length(head);
    if(pos < 0 or pos > len)
    return;

    if(pos == 0)
    {
        insertAtBeg(data,head,tail);
        return;
    }

    if(pos == len)
    {
        insertAtTail(data,head,tail);
        return;
    }

    Node *newnode = new Node(data);
    int i = 0;
    Node *temp = head;
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

// 1. Delete from Beg
void deleteFromBeg(Node *&head,Node *&tail)
{
    int len = length(head);

    if(head == NULL and tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    if(len == 1)
    {
        Node *temp = head;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;

        head = tail = NULL;
    }

    Node *temp = head;
    head->next->prev = NULL;
    head = head->next;
    temp->next = NULL;
    temp->prev = NULL;
    delete temp;
}

// 2. Delete from tail
void deleteFromTail(Node *&head,Node *&tail)
{
    int len = length(head);

    if(head == NULL and tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    if(len == 1)
    {
        Node *temp = head;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;

        head = tail = NULL;
    }

    Node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

// 3. Delete from Pos
void deleteFromPos(int pos,Node *&head,Node *&tail)
{
    int len = length(head);

    if(head == NULL and tail == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    if(pos < 0 or pos >= len)
    return;

    if(pos == 0)
    {
        deleteFromBeg(head,tail);
        return;
    }

    if(pos == len - 1)
    {
        deleteFromTail(head,tail);
        return;
    }

    Node *temp = head;
    int i = 0;
    while(i < pos and temp->next != 0)
    {
        temp = temp->next;
        i++;
    }

    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtBeg(30,head,tail);
    print(head);
    insertAtBeg(20,head,tail);
    print(head);
    insertAtBeg(10,head,tail);
    print(head);
    insertAtTail(60,head,tail);
    print(head);
    insertAtTail(70,head,tail);
    print(head);
    insertAtPos(3,50,head,tail);
    print(head);
    insertAtPos(3,40,head,tail);
    print(head);
    deleteFromBeg(head,tail);
    print(head);
    deleteFromTail(head,tail);
    print(head);
    deleteFromPos(2,head,tail);
    print(head);
    deleteFromPos(2,head,tail);
    print(head);

    return 0;
}
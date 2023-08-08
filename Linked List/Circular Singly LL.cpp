#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int data = 0)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    if(head == NULL)
    {
        cout << "Empty" << endl;
        return;
    }

    Node *temp = head;
    while(temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void insertAtHead(int data,Node *&head,Node *&tail)
{
    Node *newnode = new Node(data);

    if(head == NULL and tail == NULL)
    {
        head = newnode;
        head->next = head;
        tail = head;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        tail->next = head;
    }
}

void insertAtTail(int data,Node *&head,Node *&tail)
{
    Node *newnode = new Node(data);

    if(head == NULL and tail == NULL)
    {
        head = newnode;
        head->next = head;
        tail = head;
    }
    else
    {
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

int length(Node *&head)
{
    int count = 0;

    if(head == NULL)
    return count;

    Node *temp = head;
    while(temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    return count + 1;
}

void insertAtPos(int pos,int data,Node *&head,Node *&tail)
{
    Node *newnode = new Node(data);

    int len = length(head);

    if(pos < 0 or pos > len)
    return;

    if(pos == 0)
    {
        insertAtHead(data,head,tail);
        return;
    }

    if(pos == len)
    {
        insertAtTail(data,head,tail);
        return;
    }

    Node *temp = head;
    int i = 0;
    while(i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    
}

void deleteFromBeg(Node *&head,Node *&tail)
{
    if(head == NULL and tail == NULL)
    return;

    if(head->next == head)
    {
        Node *temp = head;
        temp->next = NULL;
        delete temp;
        head = tail = NULL;
        return;
    }

    Node *temp = head;
    tail->next = head->next;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteFromEnd(Node *&head,Node *&tail)
{
    if(head == NULL and tail == NULL)
    return;

    if(head->next == head)
    {
        Node *temp = head;
        temp->next = NULL;
        delete temp;
        head = tail = NULL;
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    while(temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    temp->next = NULL;
    delete temp;
}

void deleteFromPos(int pos,Node *&head,Node *&tail)
{
    if(head == NULL and tail == NULL)
    return;

    int len = length(head);

    if(pos < 0 or pos >= len)
    return;

    if(pos == 0)
    {
        deleteFromBeg(head,tail);
        return;
    }

    if(pos == len - 1)
    {
        deleteFromEnd(head,tail);
        return;
    }

    Node *temp = head;
    Node *prev = NULL;
    int i = 0;
    while(i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(30,head,tail);
    print(head);
    insertAtHead(20,head,tail);
    print(head);
    insertAtHead(10,head,tail);
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
    deleteFromEnd(head,tail);
    print(head);
    deleteFromPos(2,head,tail);
    print(head);
    deleteFromPos(2,head,tail);
    print(head);

    return 0;
}
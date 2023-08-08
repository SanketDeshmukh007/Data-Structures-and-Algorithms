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

class MyLinkedList
{
public:
    Node *head;
    Node *tail;

    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int length()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int get(int index)
    {
        int len = length();
        if (index < 0 or index >= len)
            return -1;

        Node *temp = head;
        int i = 0;
        while (i < index)
        {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    void addAtHead(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL and tail == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void addAtTail(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL and tail == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void addAtIndex(int index, int val)
    {
        int len = length();
        if (index < 0 or index > len)
            return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        if (index == len)
        {
            addAtTail(val);
            return;
        }

        int i = 0;
        Node *temp = head;
        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }

        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void deleteAtIndex(int index)
    {
        int len = length();
        if (index < 0 or index >= len)
            return;

        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            if (len == 1)
            {
                tail = NULL;
            }
            return;
        }

        Node *temp = head;
        int i = 0;
        Node *prev = NULL;
        while (i < index and temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        if (index == len - 1)
        {
            tail = prev;
        }
    }

    void print()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }
};

int main()
{
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);    // linked list becomes 1->2->3
    myLinkedList->print();
    myLinkedList->get(1);              // return 2
    myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
    myLinkedList->print();
    myLinkedList->get(1);  
}

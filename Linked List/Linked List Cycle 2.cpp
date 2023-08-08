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

Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool loop = false;

    while (fast != 0)
    {
        fast = fast->next;
        if (fast != 0)
        {
            fast = fast->next;

            slow = slow->next;
        }

        if (slow == fast)
        {
            loop = true;
            slow = head;
            break;
        }
    }

    if (loop == false)
    {
        return NULL;
    }

    while (slow != fast)
    {
        fast = fast->next;

        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = fifth;

    cout << "Starting of loop is at : " << detectCycle(head)->data << endl;

    return 0;
}
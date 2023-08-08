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

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;

    while(curr != 0)
    {
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *addTwoNumbers(Node *head1,Node* head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    if(head1 == NULL and head2 == NULL)
        return NULL;
    // Step 1 : Reverse both LL
    head1 = reverse(head1);
    head2 = reverse(head2);

    // Step 2 : Add Two LL
    Node *num1 = head1;
    Node *num2 = head2;
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    int carry = 0;

    while(num1 != 0 or num2 != 0 or carry != 0)
    {
        int val1 = 0;
        int val2 = 0;
        if(num1 != NULL)
            val1 = num1->data;
        if(num2 != NULL)
            val2 = num2-> data;


        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        Node *newnode = new Node(digit);
        anstail->next = newnode;
        anstail = anstail->next;
        carry = sum / 10;

        if(num1 != 0)
            num1 = num1 -> next;
        if(num2 != 0)
            num2 = num2->next;
    }

    anshead = anshead->next;
    // Step 3 : Reverse ans LL
    Node *head = reverse(anshead);
    return head;
}

int main()
{
    Node *head1 = new Node(2);
    Node *first = new Node(4);
    Node *head2 = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head1->next = first;
    head2->next = third;
    third->next = fourth;

    print(head1);
    print(head2);

    Node *head = addTwoNumbers(head1,head2);
    print(head);

    return 0;
}

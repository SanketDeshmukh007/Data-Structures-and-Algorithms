#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insertAtTail(int val, ListNode *&newhead, ListNode *&newtail)
{
    ListNode *newnode = new ListNode(val);
    if (newhead == NULL and newtail == NULL)
    {
        newhead = newtail = newnode;
    }
    else
    {
        newtail->next = newnode;
        newtail = newnode;
    }
}
ListNode *mergeNodes(ListNode *head)
{

    ListNode *temp = head->next;
    ListNode *newhead = NULL;
    ListNode *newtail = NULL;

    while (temp != 0)
    {
        int sum = 0;
        while (temp != 0 and temp->val != 0)
        {
            sum += temp->val;
            temp = temp->next;
        }
        insertAtTail(sum, newhead, newtail);

        temp = temp->next;
    }

    return newhead;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val;
        if (current->next != nullptr)
        {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << " -> NULL" << endl;
}

int main()
{
    // Create and initialize the linked list
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(0);

    cout << "Original Linked List:" << endl;
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    ListNode *mergedHead = mergeNodes(head);

    cout << "Merged Linked List:" << endl;
    current = mergedHead;
    while (current != nullptr)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

    // Clean up memory
    current = mergedHead;
    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{

    if (head == 0)
        return head;

    ListNode *prev = head;
    ListNode *curr = head->next;

    while (curr != 0)
    {
        if (prev->val == curr->val)
        {
            ListNode *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

ListNode *deleteDuplicates1(ListNode *head)
{

    if (head == 0)
        return head;

    ListNode *curr = head;

    while (curr != 0)
    {
        while (curr->next != 0 and curr->val == curr->next->val)
        {
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }

        curr = curr->next;
    }
    return head;
}

void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int main()
{
    // Create the linked list with values 1, 2, 3, 4, and 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);

    // Print the linked list to verify it's created correctly
    print(head);

    head = deleteDuplicates1(head);
    print(head);

    // Don't forget to delete the nodes to free memory
    ListNode *temp = head;
    while (temp != nullptr)
    {
        ListNode *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
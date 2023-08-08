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

ListNode *removeElements(ListNode *head, int val)
{

    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        if (head->val == val)
        {
            head = NULL;
            return head;
        }
    }

    ListNode *temp = head;
    while (temp != 0 and temp->val == val)
    {
        ListNode *node = temp;
        temp = temp->next;
        head = head->next;
        delete node;
    }

    temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        while (temp != 0 and temp->val == val)
        {
            ListNode *node = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete node;
        }
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
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    // Print the linked list to verify it's created correctly
    print(head);

    head = removeElements(head, 5);
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
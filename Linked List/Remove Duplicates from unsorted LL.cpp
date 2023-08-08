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

    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != 0)
    {
        prev = curr;
        ListNode *temp = curr->next;

        while(temp != 0)
        {
            if(curr->val == temp->val)
            {
                prev->next = temp->next;
                temp = temp->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

ListNode *deleteDuplicates1(ListNode *&head)
{
    unordered_map<int,bool> m;
    ListNode *temp = head;
    ListNode *prev = head;

    while(temp != 0)
    {
        if(m[temp->val] == false)
        {
            m[temp->val] = true;
            prev = temp;
            temp = temp->next;
        }
        else
        {
            prev->next = temp->next;
            temp = temp->next;
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
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(7);

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
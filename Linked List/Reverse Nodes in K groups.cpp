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

int length(ListNode *&head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode *reverseKGroup(ListNode *&head, int k)
{

    // Base Case : Empty or Single Node
    if (head == 0 or head->next == 0)
        return head;

    int len = length(head);
    if (k > len)
        return head;

    // Step 1 : Reverse first k Nodes
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nextNode = curr->next;
    int count = 0;

    while (count < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // Step 2 : Recursive Call for remaining Nodes
    if (nextNode != 0)
    {
        head->next = reverseKGroup(nextNode, k);
    }

    // Step 3 : Return head of modified linked list
    return prev;
}

void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl << endl;
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

    head = reverseKGroup(head, 3);
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
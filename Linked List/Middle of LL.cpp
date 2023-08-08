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

int length(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode *middleNode(ListNode *head)
{

    int len = length(head);
    int index = len / 2;
    int i = 0;
    ListNode *temp = head;
    while (i < index and temp->next != 0)
    {
        temp = temp->next;
        i++;
    }
    return temp;
}

// 2. Tortoise Method
ListNode *middleNode2(ListNode *head)
{
    // Empty
    if (head == 0)
        return head;

    // 1 Node
    if (head->next == 0)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    // ListNode *fast = head->next;

    while (slow != 0 and fast != 0)
    {
        fast = fast->next;
        if (fast != 0)
        {
            fast = fast->next;

            slow = slow->next;
        }
    }

    return slow;
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

    ListNode *mid = middleNode2(head);
    print(mid);

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
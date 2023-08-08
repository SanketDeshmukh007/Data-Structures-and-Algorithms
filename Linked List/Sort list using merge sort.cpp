#include <iostream>

// Define the ListNode structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
        return NULL;
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    ListNode *anshead = new ListNode(-1);
    ListNode *anstail = anshead;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            ListNode *nextnode = temp1->next;
            anstail->next = temp1;
            anstail = anstail->next;
            temp1 = nextnode;
        }
        else
        {
            ListNode *nextnode = temp2->next;
            anstail->next = temp2;
            anstail = anstail->next;
            temp2 = nextnode;
        }
    }

    if (temp1 != NULL)
    {
        anstail->next = temp1;
    }

    if (temp2 != NULL)
    {
        anstail->next = temp2;
    }

    anshead = anshead->next;
    return anshead;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    ListNode *mid = slow;
    ListNode *nextnode = mid->next;
    mid->next = NULL;
    ListNode *head1 = sortList(head);
    ListNode *head2 = sortList(nextnode);

    ListNode *newhead = mergeTwoLists(head1, head2);
    return newhead;
}

int main()
{
    // Creating an unsorted linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    ListNode *sortedList = sortList(head);

    // Print the sorted linked list
    ListNode *temp = sortedList;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up memory
    while (sortedList != NULL)
    {
        ListNode *next = sortedList->next;
        delete sortedList;
        sortedList = next;
    }

    return 0;
}

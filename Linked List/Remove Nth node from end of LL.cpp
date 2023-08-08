#include <iostream>

// Define the ListNode structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to calculate the length of the linked list
int length(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to remove the nth node from the end of the linked list
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return head;
    if (head->next == NULL && n == 1)
        return NULL;

    int len = length(head);
    int diff = len - n;

    if (diff == 0)
    {
        head = head->next;
        return head;
    }

    ListNode *temp = head;
    while (diff != 1)
    {
        temp = temp->next;
        diff--;
    }
    temp->next = temp->next->next;
    return head;
}

int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end
    ListNode *result = removeNthFromEnd(head, n);

    // Print the linked list after removal
    ListNode *temp = result;
    while (temp != NULL)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up memory
    while (result != NULL)
    {
        ListNode *next = result->next;
        delete result;
        result = next;
    }

    return 0;
}

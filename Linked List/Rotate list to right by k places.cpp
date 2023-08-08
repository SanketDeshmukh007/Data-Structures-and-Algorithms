#include <iostream>

// Definition of the ListNode structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to calculate the length of the linked list
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

// Function to rotate the linked list to the right by 'k' positions
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == 0 or head->next == 0)
        return head;

    int len = length(head);
    if (k > len)
    {
        k = k % len;
    }

    if (k == 0 or k == len)
        return head;

    int i = 1;
    int destination = len - k;
    ListNode *newhead = NULL;
    ListNode *temp = head;
    while (i < destination)
    {
        temp = temp->next;
        i++;
    }
    newhead = temp->next;
    ListNode *newtail = newhead;
    while (newtail->next != 0)
    {
        newtail = newtail->next;
    }
    temp->next = NULL;
    newtail->next = head;
    return newhead;
}

// Function to create a linked list from an array
ListNode *createLinkedListFromArray(int arr[], int n)
{
    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;

    for (int i = 1; i < n; ++i)
    {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createLinkedListFromArray(arr, n);
    int k = 2;

    std::cout << "Original linked list: ";
    printLinkedList(head);

    head = rotateRight(head, k);

    std::cout << "Rotated linked list: ";
    printLinkedList(head);

    return 0;
}

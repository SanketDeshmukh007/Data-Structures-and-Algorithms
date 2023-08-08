#include <iostream>

// Define the ListNode structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val <= temp2->val) {
            ListNode *nextnode = temp1->next;
            anstail->next = temp1;
            anstail = anstail->next;
            temp1 = nextnode;
        } else {
            ListNode *nextnode = temp2->next;
            anstail->next = temp2;
            anstail = anstail->next;
            temp2 = nextnode;
        }
    }

    if (temp1 != NULL) {
        anstail->next = temp1;
    }

    if (temp2 != NULL) {
        anstail->next = temp2;
    }

    anshead = anshead->next;
    return anshead;
}

int main() {
    // Creating two sorted linked lists: 1 -> 3 -> 5 and 2 -> 4 -> 6
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode *mergedList = mergeTwoLists(list1, list2);

    // Print the merged linked list
    ListNode *temp = mergedList;
    while (temp != NULL) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;

    // Clean up memory
    while (mergedList != NULL) {
        ListNode *next = mergedList->next;
        delete mergedList;
        mergedList = next;
    }

    return 0;
}

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

int length(ListNode *head)
{
    ListNode *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int len1 = length(headA);
    int len2 = length(headB);

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff--)
            headA = headA->next;
    }
    else
    {
        int diff = len2 - len1;
        while (diff--)
            headB = headB->next;
    }

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != nullptr)
    {
        if (temp1 == temp2)
            return temp1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}

void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << "Value: " << curr->val << " ";
        
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating nodes for listA
    ListNode *a1 = new ListNode(4);
    ListNode *a2 = new ListNode(1);
    ListNode *intersection = new ListNode(8);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);

    // Creating nodes for listB
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(1);

    // Setting next pointers for listA
    a1->next = a2;
    a2->next = intersection;
    intersection->next = a4;
    a4->next = a5;

    // Setting next pointers for listB
    b1->next = b2;
    b2->next = b3;
    b3->next = intersection;

    printList(a1);
    printList(b1);

    // Output the intersection node value
    ListNode *intersectionNode = getIntersectionNode(a1, b1);
    if (intersectionNode != nullptr)
    {
        std::cout << "Intersection node value: " << intersectionNode->val << std::endl;
    }
    else
    {
        std::cout << "No intersection found." << std::endl;
    }

    return 0;
}

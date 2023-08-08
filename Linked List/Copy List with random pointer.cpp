#include <iostream>

struct Node
{
    int val;
    Node *next;
    Node *random;
    Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

Node *copyRandomList(Node *head)
{

    if (head == 0)
        return head;

    Node *curr = head;
    Node *nextnode = NULL;

    // Step 1 : Create a clone list and add clonenodes in betn original list
    while (curr != 0)
    {
        nextnode = curr->next;
        Node *newnode = new Node(curr->val);
        curr->next = newnode;
        newnode->next = nextnode;
        curr = nextnode;
    }

    // Step 2 : Copy random pointers
    curr = head;
    while (curr != 0)
    {
        if (curr->next != 0 and curr->random != 0)
            curr->next->random = curr->random->next;

        curr = curr->next->next;
    }

    // Step 3 : Revert changes done in step 1
    Node *original = head;
    Node *copy = head->next;
    Node *temp = copy;
    while (original != NULL)
    {
        original->next = original->next->next;
        original = original->next;
        if (copy->next != NULL)
        {
            copy->next = copy->next->next;
            copy = copy->next;
        }
    }
    return temp;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        std::cout << "Value: " << curr->val;
        if (curr->random != nullptr)
            std::cout << ", Random: " << curr->random->val;
        std::cout << std::endl;
        curr = curr->next;
    }
}

int main()
{
    // Creating nodes
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    // Setting next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    // Setting random pointers
    node1->random = node3;
    node2->random = node5;
    node3->random = node2;
    node4->random = node1;
    node5->random = node4;

    std::cout << "Original List:" << std::endl;
    printList(node1);

    // Copy the list
    Node *copiedList = copyRandomList(node1);

    std::cout << "Copied List:" << std::endl;
    printList(copiedList);

    return 0;
}
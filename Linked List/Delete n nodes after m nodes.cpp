#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

void printLinkedList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Corrected linkdelete function
void linkdelete(Node *head, int M, int N)
{
    if(head == 0) return;

    Node *temp = head;

    while(temp != 0)
    {
        for(int i = 1; i < M and temp != 0; i++)
        {
            temp = temp->next;
        }

        if(temp == 0) return;

        Node *todelete = temp->next;
        for(int i = 0; i < N and todelete != 0; i++)
        {
            Node *nextnode = todelete->next;
            delete todelete;
            todelete = nextnode;
        }

        temp->next = todelete;
        temp = todelete;
    }
}

int main()
{
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    std::cout << "Original linked list: ";
    printLinkedList(head);

    int M = 2; // Number of nodes to skip
    int N = 1; // Number of nodes to delete

    linkdelete(head, M, N);

    std::cout << "Linked list after deletion: ";
    printLinkedList(head);

    // Clean up memory (deallocate nodes)
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

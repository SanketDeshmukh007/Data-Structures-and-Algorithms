#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int val) : data(val), next(nullptr), bottom(nullptr) {}
};

Node *merge(Node *head1, Node *head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    Node *ans = nullptr;

    if (head1->data <= head2->data)
    {
        ans = head1;
        ans->bottom = merge(head1->bottom, head2);
    }
    else
    {
        ans = head2;
        ans->bottom = merge(head1, head2->bottom);
    }
    return ans;
}

Node *flatten(Node *root)
{
    if (root == nullptr)
        return root;

    Node *mergelistHead = merge(root, flatten(root->next));
    root->next = nullptr;
    return mergelistHead;
}

void printFlattenedList(Node *flattenedList)
{
    while (flattenedList != nullptr)
    {
        std::cout << flattenedList->data << " ";
        flattenedList = flattenedList->bottom;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a sample linked list with the given structure
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->bottom = new Node(5);
    node1->bottom->bottom = new Node(8);

    node2->bottom = new Node(6);

    node3->bottom = new Node(7);
    node3->bottom->bottom = new Node(9);

    node4->bottom = new Node(10);

    // Calling the flatten function
    Node *flattenedList = flatten(node1);

    // Printing the flattened linked list
    printFlattenedList(flattenedList);

    return 0;
}

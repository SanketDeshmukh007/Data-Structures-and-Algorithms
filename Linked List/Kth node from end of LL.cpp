#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *next;
} node;

// Function to calculate the length of the linked list
int length(node *head) {
    int count = 0;
    node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to find the kth node from the end of the linked list
node *findKthFromLast(node *head, int k) {
    int len = length(head);
    int diff = len - k;

    node *temp = head;
    while (diff > 0) {
        temp = temp->next;
        diff--;
    }
    return temp;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    node *head = (node *)malloc(sizeof(node));
    head->data = 1;
    
    node *current = head;
    for (int i = 2; i <= 5; i++) {
        current->next = (node *)malloc(sizeof(node));
        current = current->next;
        current->data = i;
    }
    current->next = NULL;

    int k = 2; // Find the 2nd node from the end
    node *result = findKthFromLast(head, k);

    if (result != NULL) {
        printf("The %dth node from the end is: %d\n", k, result->data);
    } else {
        printf("Invalid input or index out of bounds.\n");
    }

    // Free the allocated memory
    current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

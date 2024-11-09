#include <stdio.h>
#include "linked_list.h"

int main() {
    // Initialize empty list
    Node* head = NULL;
    
    // Build initial list: 5 -> 10 -> 20 -> 30
    insertAtEnd(&head, 5);     // Add 5 at end:  5 -> NULL
    insertAtEnd(&head, 10);    // Add 10 at end: 5 -> 10 -> NULL
    insertAtEnd(&head, 20);    // Add 20 at end: 5 -> 10 -> 20 -> NULL
    insertAtEnd(&head, 30);    // Add 30 at end: 5 -> 10 -> 20 -> 30 -> NULL
    
    // Display initial list
    printf("Initial list: ");
    printList(head);
    
    // Show total number of nodes
    printf("Number of nodes: %d\n", countNodes(head));
    
    // Delete node with value 20
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);
    
    // Clean up memory before exiting
    freeList(&head);
    return 0;
}
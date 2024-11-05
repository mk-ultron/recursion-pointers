#include <stdio.h>
#include "linked_list.h"

int main() {
    Node* head = NULL;
    
    // Test insertions
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    
    printf("Initial list: ");
    printList(head);
    
    printf("Number of nodes: %d\n", countNodes(head));
    
    // Test deletion
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);
    
    // Clean up
    freeList(&head);
    return 0;
}

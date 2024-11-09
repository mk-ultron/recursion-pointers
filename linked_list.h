#ifndef LINKED_LIST_H  // Header guard prevents multiple inclusion of this file
#define LINKED_LIST_H

// Define the structure for each node in our linked list
typedef struct Node {
    int data;          // The actual value stored in the node
    struct Node* next; // Pointer to the next node (NULL if this is the last node)
} Node;

// Function Declarations:

// Creates a new node with given data
// Returns: Pointer to the newly created node
Node* createNode(int data);

// Adds a new node at the start of the list
// Parameters: head - pointer to pointer of first node (allows modifying head)
//            data - value to be inserted
void insertAtBeginning(Node** head, int data);

// Adds a new node at the end of the list
// Parameters: same as insertAtBeginning
void insertAtEnd(Node** head, int data);

// Removes first occurrence of node with given data
// Parameters: same as insertAtBeginning, but data is value to delete
void deleteNode(Node** head, int data);

// Displays all nodes in the list
// Parameters: head - pointer to first node
void printList(Node* head);

// Counts total number of nodes using recursion
// Parameters: head - pointer to first node
// Returns: integer count of nodes
int countNodes(Node* head);

// Deallocates all memory used by the list
// Parameters: head - pointer to pointer of first node
void freeList(Node** head);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createNode(int data) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);  // Exit program if we can't allocate memory
    }
    
    // Initialize the node's values
    newNode->data = data;  // Set the data
    newNode->next = NULL;  // New node initially points to nothing
    
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    // Create the new node
    Node* newNode = createNode(data);
    
    // Make new node point to current head
    newNode->next = *head;
    
    // Make new node the head
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    // Create the new node
    Node* newNode = createNode(data);
    
    // If list is empty, make new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Otherwise, traverse to last node
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Make last node point to new node
    current->next = newNode;
}

void deleteNode(Node** head, int data) {
    // If list is empty, nothing to delete
    if (*head == NULL) return;
    
    Node* temp = *head;
    Node* prev = NULL;
    
    // If head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Change head
        free(temp);         // Free old head
        return;
    }
    
    // Search for the node to be deleted
    // Keep track of the previous node as we need to adjust its next pointer
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    // If data wasn't present in linked list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    // Free memory
    free(temp);
}

void printList(Node* head) {
    // Check if list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    // Traverse and print each node
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");  // Show end of list
}

int countNodes(Node* head) {
    // Base case: if head is NULL, return 0
    if (head == NULL) return 0;
    
    // Recursive case: count this node (1) plus all nodes after it
    return 1 + countNodes(head->next);
}

void freeList(Node** head) {
    Node* current = *head;
    Node* next;
    
    // Traverse list and free each node
    while (current != NULL) {
        next = current->next;  // Save next node
        free(current);         // Free current node
        current = next;        // Move to next node
    }
    
    // Set head to NULL as list is now empty
    *head = NULL;
}
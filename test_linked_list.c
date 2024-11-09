// test_linked_list.c
#include <stdio.h>
#include "linked_list.h"

// Function to print test results
void printTestResult(const char* testName, int passed) {
    printf("%s: %s [%s]\n", testName, passed ? "PASSED" : "FAILED", passed ? "OK" : "X");
}

// 1. Basic Function Tests
void runBasicTests() {
    printf("\n=== Running Basic Function Tests ===\n");
    Node* head = NULL;
    int testsPassed = 0;
    
    // Test 1: Insert at beginning
    insertAtBeginning(&head, 10);
    printTestResult("Insert at beginning", head != NULL && head->data == 10);
    
    // Test 2: Insert at end
    insertAtEnd(&head, 20);
    printTestResult("Insert at end", head->next != NULL && head->next->data == 20);
    
    // Test 3: Count nodes
    printTestResult("Count nodes", countNodes(head) == 2);
    
    // Test 4: Delete node
    deleteNode(&head, 10);
    printTestResult("Delete node", head->data == 20);
    
    // Clean up
    freeList(&head);
}

// 2. Real-World Usage Tests
void runUsageTests() {
    printf("\n=== Running Real-World Usage Tests ===\n");
    Node* head = NULL;
    
    // Test Case: Creating a simple todo list
    printf("\nTest Case: Todo List\n");
    printf("- Adding tasks...\n");
    
    insertAtEnd(&head, 1);  // Task 1
    insertAtEnd(&head, 2);  // Task 2
    insertAtEnd(&head, 3);  // Task 3
    
    printf("Todo List: ");
    printList(head);
    
    printf("- Completing task 2...\n");
    deleteNode(&head, 2);
    
    printf("Updated Todo List: ");
    printList(head);
    
    printf("Tasks remaining: %d\n", countNodes(head));
    
    // Clean up
    freeList(&head);
}

int main() {
    printf("Starting Linked List Tests...\n");
    
    // Run both types of tests
    runBasicTests();
    runUsageTests();
    
    printf("\nAll tests completed!\n");
    return 0;
}
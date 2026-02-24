#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete first occurrence of key
struct Node* deleteFirstOccurrence(struct Node* head, int key) {
    
    // If list is empty
    if (head == NULL)
        return NULL;

    // If head node itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    // If key not found
    if (current == NULL)
        return head;

    // Unlink the node
    previous->next = current->next;
    free(current);

    return head;
}

// Function to insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 20 -> 40
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 20);
    head = insertEnd(head, 40);

    printf("Original List:\n");
    printList(head);

    int key = 20;
    head = deleteFirstOccurrence(head, key);

    printf("After deleting first occurrence of %d:\n", key);
    printList(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Structure of linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    return count;
}

// Function to insert node at end
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

// Main function
int main() {
    struct Node* head = NULL;

    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 2);

    int key = 2;
    int result = countOccurrences(head, key);

    printf("Element %d occurs %d times\n", key, result);

    return 0;
}
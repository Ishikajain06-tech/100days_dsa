#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to find intersection node
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (headA == NULL || headB == NULL)
        return NULL;

    struct ListNode* p1 = headA;
    struct ListNode* p2 = headB;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    return p1;  // Intersection node or NULL
}

// Helper function to create new node
struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    // Creating common part
    struct ListNode* common = createNode(8);
    common->next = createNode(10);

    // List A
    struct ListNode* headA = createNode(3);
    headA->next = createNode(6);
    headA->next->next = createNode(9);
    headA->next->next->next = common;

    // List B
    struct ListNode* headB = createNode(4);
    headB->next = common;

    struct ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL)
        printf("Intersection at node with value: %d\n", intersection->data);
    else
        printf("No intersection\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct ListNode *curr = head;
    int length = 1;

    // Step 1: Find length and last node
    while (curr->next != NULL) {
        curr = curr->next;
        length++;
    }

    // Step 2: Make it circular
    curr->next = head;

    // Step 3: Reduce k
    k = k % length;
    int stepsToNewHead = length - k;

    // Step 4: Find new tail
    struct ListNode *newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    // Step 5: Break circle
    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
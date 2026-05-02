#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    // Dummy node (helps simplify insertion at head)
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;

    struct ListNode* current = head;

    while (current) {
        struct ListNode* nextNode = current->next;

        // Find position to insert
        struct ListNode* prev = dummy;
        while (prev->next && prev->next->val < current->val) {
            prev = prev->next;
        }

        // Insert current node
        current->next = prev->next;
        prev->next = current;

        // Move to next node
        current = nextNode;
    }

    return dummy->next;
}

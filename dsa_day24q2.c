struct ListNode* removeElements(struct ListNode* head, int val) {
    
    // Create dummy node
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    
    struct ListNode* current = dummy;
    
    while (current->next != NULL) {
        if (current->next->val == val) {
            // Node to delete
            struct ListNode* temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    
    struct ListNode* newHead = dummy->next;
    free(dummy);
    
    return newHead;
}

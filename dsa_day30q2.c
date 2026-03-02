#include <stdio.h>
#include <stdlib.h>

/* Stack structure */
struct Stack {
    int *arr;
    int top;
    int capacity;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int val) {
    stack->arr[++stack->top] = val;
}

int pop(struct Stack* stack) {
    return stack->arr[stack->top--];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct Stack* s1 = createStack(1000);
    struct Stack* s2 = createStack(1000);

    // Push all digits to stacks
    while (l1) {
        push(s1, l1->val);
        l1 = l1->next;
    }

    while (l2) {
        push(s2, l2->val);
        l2 = l2->next;
    }

    int carry = 0;
    struct ListNode* result = NULL;

    // Pop and add
    while (!isEmpty(s1) || !isEmpty(s2) || carry) {
        int sum = carry;

        if (!isEmpty(s1))
            sum += pop(s1);

        if (!isEmpty(s2))
            sum += pop(s2);

        carry = sum / 10;

        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;

        // Insert at beginning
        newNode->next = result;
        result = newNode;
    }

    free(s1->arr);
    free(s1);
    free(s2->arr);
    free(s2);

    return result;
}

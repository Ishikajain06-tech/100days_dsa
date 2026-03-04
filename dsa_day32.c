#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;   // Initially stack is empty

// Function to check if stack is full
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

// Function to check if stack is empty
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// PUSH Operation
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// POP Operation
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        int popped = stack[top];
        top--;
        return popped;
    }
}

// Display Stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

// Main Function
int main() {
    push(10);
    push(20);
    push(30);
    display();

    printf("Popped element: %d\n", pop());
    display();

    return 0;
}
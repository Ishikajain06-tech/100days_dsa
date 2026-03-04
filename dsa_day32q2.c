#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
} MinStack;

// Constructor
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

// Push
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->stack[obj->top] = val;
    
    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    } else {
        int currentMin = obj->minStack[obj->top - 1];
        obj->minStack[obj->top] = (val < currentMin) ? val : currentMin;
    }
}

// Pop
void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {
        obj->top--;
    }
}

// Top
int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

// Get Minimum
int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

// Free Memory
void minStackFree(MinStack* obj) {
    free(obj);
}

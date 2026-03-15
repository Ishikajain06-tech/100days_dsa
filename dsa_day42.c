#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x)
{
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;
        queue[++rear] = x;
    }
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

void reverseQueue()
{
    while(front <= rear)     // Move queue elements to stack
    {
        push(dequeue());
    }

    front = 0;
    rear = -1;

    while(top != -1)         // Move stack elements back to queue
    {
        enqueue(pop());
    }
}

void display()
{
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue:\n");
    display();

    reverseQueue();

    printf("Reversed Queue:\n");
    display();

    return 0;
}
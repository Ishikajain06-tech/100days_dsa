#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);

    display();

    deleteFront();
    deleteRear();

    display();

    return 0;
}
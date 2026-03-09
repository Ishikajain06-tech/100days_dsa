#include <stdio.h>

#define MAX 5

int pq[MAX];
int n = 0;

void insert(int value)
{
    if(n == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }

    int i = n - 1;

    while(i >= 0 && pq[i] < value)
    {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    n++;

    printf("%d inserted\n", value);
}

void delete()
{
    if(n == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }

    printf("%d deleted\n", pq[0]);

    for(int i = 0; i < n - 1; i++)
        pq[i] = pq[i + 1];

    n--;
}

void display()
{
    if(n == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", pq[i]);

    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
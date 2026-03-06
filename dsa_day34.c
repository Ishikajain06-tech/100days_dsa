#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char exp[])
{
    int i = 0;
    
    while(exp[i] != '\0')
    {
        // If operand, push to stack
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0'); 
        }
        else
        {
            int val1 = pop();
            int val2 = pop();
            
            switch(exp[i])
            {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
        i++;
    }
    
    return pop();
}

int main()
{
    char exp[] = "231*+9-";
    
    printf("Result = %d", evaluatePostfix(exp));
    
    return 0;
}
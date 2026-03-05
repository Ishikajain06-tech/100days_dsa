#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char x) {
    if(x == '^')
        return 3;
    else if(x == '*' || x == '/')
        return 2;
    else if(x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {

    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0') {

        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        else if(infix[i] == '(') {
            push(infix[i]);
        }

        else if(infix[i] == ')') {
            while(stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }

        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }

        i++;
    }

    while(top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s", postfix);

    return 0;
}
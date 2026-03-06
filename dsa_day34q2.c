#include <stdio.h>
#include <ctype.h>

int calculate(char* s) {
    int stack[10000];
    int top = -1;

    int num = 0;
    char sign = '+';

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0')
        {
            if(sign == '+')
                stack[++top] = num;

            else if(sign == '-')
                stack[++top] = -num;

            else if(sign == '*')
                stack[top] = stack[top] * num;

            else if(sign == '/')
                stack[top] = stack[top] / num;

            sign = s[i];
            num = 0;
        }
    }

    int result = 0;
    for(int i = 0; i <= top; i++)
        result += stack[i];

    return result;
}

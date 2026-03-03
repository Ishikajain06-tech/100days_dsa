#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int n = strlen(s);
    
    // Create stack
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // If opening bracket, push
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // If closing bracket
        else {
            if (top == -1) {   // No matching opening
                free(stack);
                return false;
            }

            char topChar = stack[top--];

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);  // Stack should be empty
    free(stack);
    return valid;
}

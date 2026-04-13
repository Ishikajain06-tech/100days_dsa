#include <stdio.h>

char firstRepeatedChar(char str[]) {
    int count[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++;

        if (count[(int)str[i]] == 2) {
            return str[i];
        }
    }

    return '\0'; // No repeated character
}

int main() {
    char str[] = "programming";

    char result = firstRepeatedChar(str);

    if (result != '\0')
        printf("First repeated character: %c\n", result);
    else
        printf("No repeated character found\n");

    return 0;
}
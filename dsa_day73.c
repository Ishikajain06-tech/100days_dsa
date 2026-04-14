#include <stdio.h>
#include <string.h>

char firstNonRepeating(char *str) {
    int freq[256] = {0};  // ASCII size

    // Count frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Find first non-repeating character
    for (int i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }

    return '\0'; // If no non-repeating character found
}

int main() {
    char str[] = "programming";

    char result = firstNonRepeating(str);

    if (result != '\0')
        printf("First non-repeating character: %c\n", result);
    else
        printf("No non-repeating character found.\n");

    return 0;
}
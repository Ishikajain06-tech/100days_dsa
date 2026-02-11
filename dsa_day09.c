#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int i, length;

    printf("Enter the code name: ");
    scanf("%s", name);

    length = strlen(name);

    printf("Mirrored code name: ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }

    return 0;
}

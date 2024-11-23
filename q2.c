#include <stdio.h>
#include <string.h>

void reverseString(char str[], int index, char reversed[]) {
    if (str[index] == '\0') {
        reversed[index] = '\0';
        return;
    }
    reverseString(str, index + 1, reversed);
    reversed[strlen(str) - index - 1] = str[index];
}//end fnction reverseString

int main() {
    char str[20];
    printf("Enter a string: ");
    scanf("%s",str);
    char reversed[20];
    reverseString(str, 0, reversed);
    printf("Reversed string: %s\n", reversed);
    return 0;
}

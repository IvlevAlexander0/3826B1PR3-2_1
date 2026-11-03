#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    char s[100];
    int word_count = 0;
    int number_count = 0;

    printf("Enter string: ");

    while (scanf("%99s", s) == 1) {
        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')) {
            word_count++;
        }
        else if (s[0] >= '0' && s[0] <= '9') {
            number_count++;
        }

        if (getchar() == '\n') {
            break;
        }
    }

    printf("Word count: %d\n", word_count);
    printf("Number count: %d\n", number_count);

    return 0;
}
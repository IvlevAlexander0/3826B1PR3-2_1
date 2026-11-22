#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int user_num(int num) {
    int unum = 0;
    int c1num = 10;
    int c2num = 99;
    int n = num - 2;
    while (n != 0) {
        c1num = c1num * 10;
        c2num = c2num * 10 + 9;
        n = n - 1;
    }
    int b = 0;
    int b1 = 0;
    while (b1 != 1) {
        b1 = 1;
        while (b != 1) {
            unum = 0;
            b = 1;
            printf("Enter a number consisting of the same quantity of digits as you previously entered, with no repeating digits. \n");
            char str[7];
            if (scanf("%6s", str) != 1) {
                printf("Error \n");
                b = 0;
                continue;
            }
            else {
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
            }
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    printf("Error: '%c' is not number \n", str[i]);
                    b = 0;
                }
            }
            if (b == 0) {
                continue;
            }
            if (str[0] == '0') {
                printf("A number must not begin with a leading zero. \n");
                b = 0;
                continue;
            }
            int arr[10] = { 0 };
            for (int i = 0; str[i] != '\0'; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    b = 0;
                    break;
                }
                int d = str[i] - '0';
                if (arr[d]) {
                    printf("Number %d is repeated \n", d);
                    b = 0;
                }
                arr[d] = 1;
                unum = unum * 10 + d;
            }
            if (b == 0) {
                continue;
            }
        }
        if (unum < c1num || unum > c2num) {
            printf("Enter a number with the same number of digits as you previously entered. \n");
            b1 = 0;
            b = 0;
        }
    }
    return unum;
}

int gen(int num) {
    int n = num - 1;
    int digit = rand() % 9 + 1;
    int arr[5];
    arr[0] = digit;
    int p = 1;
    while (n != 0) {
        int d = rand() % 10;
        int b = 1;
        for (int i = 0; i < 5; i++) {
            if (d == arr[i]) {
                b = 0;
            }
        }
        if (b != 0) {
            digit = digit * 10 + d;
            arr[p] = d;
            p = p + 1;
            n = n - 1;
        }
    }
    return digit;
}

int main() {
	srand((unsigned int)time(NULL));
    int num;
    printf("Choose the length of the number to be guessed (from 2 to 5) \n");
    while (scanf("%d", &num) != 1 || num <= 1 || num > 5) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {};
        printf("Enter the length of the number to be guessed (from 2 to 5) \n");
    }
    int digit = gen(num);
    int d = digit;
    int unum = 0;
    int u;
    int arru[5];
    int arrd[5];
    int bulls;
    int cows;
    for (int i = 0; i < num; i++) {
        arrd[i] = d % 10;
        d = d / 10;
    }
    printf("The computer selects an n-digit number; you enter your own guesses, \n");
    printf("and it reports the number of 'cows' and 'bulls' repeat this process until you have guessed the entire number. \n");
    while (unum != digit) {
        bulls = 0;
        cows = 0;
        printf("Enter your number: \n");
        unum = user_num(num);
        u = unum;
        if (unum != digit) {
            for (int i = 0; i < num; i++) {
                arru[i] = u % 10;
                u = u / 10;
            }
            for (int i = 0; i < num; i++) {
                if (arru[i] == arrd[i]) {
                    bulls = bulls + 1;
                }
                else {
                    for (int j = 0; j < num; j++) {
                        if (arru[i] == arrd[j] && i != j) {
                            cows = cows + 1;
                        }
                    }
                }
            }
            printf("Result: %d 'bulls' and %d 'cows' \n", bulls, cows);
        }
    }
    printf("Congratulations, you guessed the number! \n");
    return 0;
}
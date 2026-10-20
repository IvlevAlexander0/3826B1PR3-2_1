#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void num_gues() {
    srand((unsigned int)time(NULL));
    int rnum = rand() % 1000 + 1;
    int unum = 0;
    int a = 1;
    printf("Guess a number (from 1 to 1000) \n");
    while (unum != rnum) {
        while (scanf("%d", &unum) != 1 || unum <= 0 || unum > 1000) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Enter a number from 1 to 1000 \n");
        }
        if(unum < rnum) {
            printf("the guessed number is greater \n");
            a = a + 1;
        }
        else if (unum > rnum) {
            printf("the chosen number is smaller \n");
            a = a + 1;
        }
    }
    printf("You guessed it! \n");
    printf("Your attempts: %d", a);
}

void num_set(){
    int unum;
    int cnum = 500;
    int a = 1;
    char ch = '0';
    printf("Think of a number from 1 to 1000 \n");
    while (scanf("%d", &unum) != 1 || unum <= 0 || unum > 1000) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {};
        printf("Enter a number from 1 to 1000 \n");
    }
    while (ch != '=') {
        printf("I think the number you have in mind is %d", cnum);
        printf(" is this correct? (Enter > if the number is greater, < if the number is smaller, and = if the program guessed correctly) \n");
        while (scanf(" %c", &ch) != 1 || ch != '>' && ch != '<' && ch != '=') {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {};
            printf("Enter > if the number is greater, < if the number is smaller, and = if the program guessed correctly \n");
        }
        if (ch == '<') {
            if (cnum <= unum) {
                printf("That is not correct; please enter it correctly. \n");
            }
            else {
                cnum = cnum - (cnum / 2);
                a = a + 1;
            }
        }
        if (ch == '>') {
            if (cnum >= unum) {
                printf("That is not correct; please enter it correctly. \n");
            }
            else {
                cnum = cnum + (cnum / 2);
                a = a + 1;
            }
        }
        if (ch == '=') {
            if (cnum != unum) {
                printf("That is not correct; please enter it correctly. \n");
                ch = '0';
            }
        }
    }
    printf("My attempts: %d", a);
}

void main()
{
    int mode;
    printf("Select a mode: 1: guess the number. 2: choose a number. \n");
    while (scanf("%d", &mode) != 1 || mode <= 0 || mode > 2) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {};
        printf("Enter: 1 to switch to number-guessing mode, 2 to switch to number-setting mode \n");
    }
    if (mode == 1) {
        num_gues();
    }
    else if (mode == 2) {
        num_set();
    }
}
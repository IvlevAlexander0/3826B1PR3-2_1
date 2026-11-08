#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
	int n;
	int c;
	srand(time(NULL));
	printf("Enter a number n from 2 to 5: ");
	while (scanf("%d", &n) != 1 || n < 2 || n > 5)
	{
		while ((c = getchar()) != '\n' && c != EOF) {}
		printf("Error. Enter a number from 2 to 5: ");
	}
	while ((c = getchar()) != '\n' && c != EOF) {}
	char secret[5];
	int used[10] = { 0 };
	for (int i = 0; i < n; i++) {
		int digit;
		do {
			digit = rand() % 10;
		} while ((i == 0 && digit == 0) || used[digit] == 1);
		secret[i] = digit + '0';
		used[digit] = 1;
	}
	int bulls = 0;
	char guess[100];
	while (bulls != n) 
	{
		printf("Enter your %d-digit guess: ", n);
		scanf(" %s", &guess);
		if (strlen(guess) != n) {
			printf("Error! ");
			continue;
		}
		bulls = 0;
		int cows = 0;
		int right = 1;
		for (int i = 0;i < n;i++) {
			if (guess[i] < '0' || guess[i] > '9') {
				right = 0;
				break;
			}
		}
		if (!right) {
			printf("Error.Only digits are allowed!\n");
			continue;
		}
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (secret[i] == guess[j]) {
					if (i == j) {
						bulls++;
					}
					else {
						cows++;
					}
				}
			}
		}
		if (bulls == n) {
			printf("Congratulations! You guessed the number %s!\n", secret);
		}
		else {
			printf("Bulls: %d, Cows: %d\n", bulls, cows);
		}
	}
	return 0;
}
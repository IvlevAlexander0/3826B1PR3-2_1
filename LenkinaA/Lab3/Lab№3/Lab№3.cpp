#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

int main() {
	srand(time(NULL));
	int n;
	do {
		printf("The length of the number(from 2 to 5)\n");
		if (scanf("%d", &n) != 1) {
			printf("Error");
			while (getchar() != '\n');
			n = 0;
		}
	} while (n < 2 || n>5);
	char secret[6];
	int used[10] = { 0 };

	int x;
	do {
		x = rand() % 10;
	} while (x == 0);
	secret[0] = '0' + x;
	used[x] = 1;

	for (int i = 1;i < n;++i) {
		do {
			x = rand() % 10;
		} while (used[x]);
		secret[i] = '0' + x;
		used[x] = 1;
	}
	secret[n] = '\0';

	printf("The computer has quessed the number. Try to guess it!\n");

	char guess[6];
	int attempts = 0;

	while (1) {
		printf("Your option: \n");
		scanf("%5s", guess);
		while (getchar() != '\n');
		if ((int)strlen(guess) != n) {
			printf("Incorrect length. Please try again\n");
			continue;
		}
		 else if (guess[0] == '0') {
			printf("0 cannot be the first\n");
			continue;
		}
		int digit = 1;
		for (int i = 0;i < n;i++) {
			if (!isdigit(guess[i])) {
				digit = 0;
				break;
			}
		}
		if (!digit) {
			printf("Error");
			continue;
		}
		


		attempts++;

		int bulls = 0, cows = 0;
		for (int i = 0;i < n;i++) {
			if (secret[i] == guess[i]) {
				bulls++;
			}
		}
		for (int i = 0;i < n;i++) {
			for (int j=0;j < n;j++) {
				if (secret[i] == guess[j] && i != j) {
					cows++;
				}
			}
		}
		printf("Bulls: %d, Cows: %d\n", bulls, cows);

		if (bulls == n) {
			printf("You quessed if!\n secret: %s, attempts: %d\n", secret, attempts);
			break;
		}
	}
	return 0;
} 

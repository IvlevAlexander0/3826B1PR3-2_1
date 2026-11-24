#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main() {
	srand(time(NULL));

	int n;
	do {
		printf_s("the length of the number (from 2 to 5)\n");
		scanf_s("%d", &n);
	} while (n < 2 || n > 5);

	char secret[6];
	int used[10] = { 0 };

	int d;
	do {
		d = rand() % 10;
	} while (d == 0);
	secret[0] = '0' + d;
	used[d] = 1;

	for (int i = 1; i < n; ++i) {
		do {
			d = rand() % 10;
		} while (used[d]);
		secret[i] = '0' + d;
		used[d] = 1;
	}
	secret[n] = '\0';

	printf_s("The computer has guessed the number. Try to guess it!\n");

	char guess[6];
	int attempts = 0;

	while (1) {
		printf_s("your option: \n");
		scanf_s("%5s", guess, (unsigned int)sizeof(guess));
		if ((int)strlen(guess) != n) {
			printf_s("Incorrect length. Please try again\n");
			continue;
		}
		if (guess[0] == '0') {
			printf_s("0 cannot be the first\n");
			continue;
		}

		attempts++;

		int bulls = 0, cows = 0;
		for (int i = 0; i < n; i++) {
			if (secret[i] == guess[i]) {
				bulls++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (secret[i] == guess[j] && i != j) {
					cows++;
				}
			}
		}

		printf_s("bulls: %d,cows: %d\n", bulls, cows);

		if (bulls == n) {
			printf_s("You guessed it! secret: %s, attempts: %d\n", secret, attempts);
			break;
		}
	}
	return 0;
}
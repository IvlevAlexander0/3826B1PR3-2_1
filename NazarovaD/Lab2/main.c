#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int mode;
	int number;
	int guess;
	int attempts = 0;
	int max = 1000;
	int min = 1;
	char answer;
	srand(time(NULL));
	printf_s("game 'guess tne number'\n");
	printf_s("1 - the computer is thinking of a number\n");
	printf_s("2 - еhe user is thinking of a number\n");
	printf_s("choose a game mode, 1 or 2\n");
	scanf_s("%d", &mode);
	if (mode == 1) {
		number = rand() % 1000 + 1;
		printf_s("a number from 1 to 1000 has been guessed\n");
		while (1) {
			printf_s("enter your guess\n");
			scanf_s("%d", &guess);
			attempts++;
			if (guess < number) {
				printf_s("the guessed number is greater\n");
			}
			else if (guess > number) {
				printf_s("the guessed number is less\n");
			}
			else {
				printf_s("guessed\n");
				break;
			}
		}
		printf_s("number of attempts: %d\n", attempts);
	}
	else if (mode == 2) {
		printf_s("guess a number from 1 to 1000\n");
		scanf_s("%d", &number);
		if (number < 1 || number > 1000) {
			printf_s("mistake\n");
			return 0;
		}
		printf_s("choose: >, <, =\n");
		printf_s("> - your number is greater than my guess\n");
		printf_s("< - your number is less than my guess\n");
		printf_s("= - i guessed your number\n");

		while (max >= min) {
			guess = min + (max - min) / 2;

			printf_s("my guess: %d\n", guess);
			printf_s("your answer: \n");
			scanf_s(" %c", &answer);

			attempts++;

			if (answer == '=') {
				printf_s("i guessed right!\n");
				break;
			}
			else if (answer == '>') {
				min = guess + 1;
			}
			else if (answer == '<') {
				max = guess - 1;
			}
			else {
				printf_s("invalid character. Enter >, < or =\n");
				attempts--;
			}
			if (min > max) {
				printf_s("the answers contradict each other\n");
				break;
			}
		}
		printf_s("number of attempts: %d\n", attempts);
	}
	else {
		printf_s("incorrect mode selection\n");
	}
	return 0;
}


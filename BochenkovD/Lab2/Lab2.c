#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand((unsigned int)time(NULL));
	int mode;
	printf("Select the mode\n");
	printf("1.The program thinks of a number, and you guess it.\n");
	printf("2.You think of a number, and the program guesses it.\n");
	printf("Your choice: ");
	scanf("%d", &mode);
	while (mode < 1 || mode>2)
	{
		printf("Enter number 1 or 2: ");
		scanf("%d", &mode);
		if (scanf("%d", &mode) != 1)
		{
			printf("\nPlease enter an integer.\n");
			while (getchar() != '\n');
			continue;
		}
	}
	if (mode == 1)
	{
		int target = rand() % 1000 + 1;
		int guess = 0;
		int attemps = 0;
		printf("\nYou have selected mode 1. Guess the number from 1 to 1000.\n");
		while (guess != target)
		{
			printf("Enter your guess: ");
			scanf("%d", &guess);
			if (scanf("%d", &guess) != 1)
			{
				printf("\nPlease enter an integer.\n");
				while (getchar() != '\n');
				continue;
			}
			while (guess > 1000 || guess < 0)
			{
				printf("The guess must be between 1 and 1000. Enter a valid number: ");
				scanf("%d", &guess);
			}
			attemps++;
			if (guess > target)
			{
				printf("The guessed number is less.\n");
			}
			else if (guess < target)
			{
				printf("The guessed number is greater.\n");
			}
			else
			{
				printf("Congratulations!You guessed it.\n");
				printf("Number of attempts: %d", attemps);
			}
		}
	}
	if (mode == 2)
	{
		int guess;
		int low = 1, high = 1000;
		int attempts = 0;
		char answer;
		printf("\nYou have selected mode 2. Think of a number from 1 to 1000, and the program will guess it.\n");
		printf("Answer the guesses with the symbols: '>' (the hidden number is greater),\n");
		printf(" '<' (the hidden number is less), '=' (the program guessed).\n");
		while (1)
		{
			guess = low + (high - low) / 2;
			attempts++;
			printf("You guessed the number: %d?", guess);
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {}
			if (scanf_s("%c", &answer, 1) != 1)
			{
				continue;
			}
			if (answer == '=') {
				printf("The program guessed the number %d!\n", guess);
				printf("Number of attempts: %d\n", attempts);
				break;
			}
			else if (answer == '>') {
				low = guess + 1;
			}
			else if (answer == '<') {
				high = guess - 1;
			}
			else {
				printf("Error\n");
				attempts--;
			}
			if (low > high)
			{
				printf("Error. Contradictory hints given\n");
				break;
			}
		}
	}
}

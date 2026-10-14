#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int mode;
	printf(" 'Guess the Number' game\n");
	printf("Select a game mode by entering 1 or 2\n");
	printf("1-The program selects a random number from the range of 1 to 1000.\n");
	printf("2-You pick a number between 1 and 1000, and the computer guesses it.\n");
	if (scanf("%d", &mode) != 1)
	{
		printf("Error! Enter number");
		return 1;
	}

	switch (mode)
	{
	case 1: //comp
	{
		int secret = rand() % 1000 + 1;
		int user = 0;
		int attempts = 0;
		while (user != secret)
		{
			printf("Enter your guess: ");
			if (scanf("%d", &user) != 1)
			{
				printf("Error. Please enter an integer.\n");
				while (getchar() != '\n');//I looked this up because I didn't know how to fix the error.
				continue;
			}

			while (getchar() != '\n');//this too :)
			attempts++;

			if (user < secret)
			{
				printf("The chosen number is greater\n");
			}
			else if (user > secret)
			{
				printf("The chosen number is smaller\n");
			}
			else
			{
				printf("You guessed number!\n");
			}
			printf("Number of attempts: %d\n", attempts);
		}
		break;
	}
	case 2:
	{
		int secret = 0;
		printf("Enter number 1-1000: ");
		if (scanf("%d", &secret) != 1 || secret > 1000 || secret < 1)
		{
			printf("Error! A number outside the 1–1000 range\n");
			return 1;
		}
		while (getchar() != '\n');

		int low = 1;
		int high = 1000;
		int attempts = 0;
		char ans = ' ';

		while (ans != '=')
		{
			int mid = low + (high - low) / 2;
			attempts++;

			printf("Computer guesses: %d\n", mid);
			printf("Enter answer (>, < or =): ");
			scanf(" %c", &ans);

			if (ans == '>')
			{
				low = mid + 1;
			}
			else if (ans == '<')
			{
				high = mid - 1;
			}
			else if (ans == '=')
			{
				if (mid == secret)
				{
					printf("Computer guessed your number!\n");
				}
				else
				{
					printf("Wrong hints! It does not match your secret number.\n");
				}
			}
			else
			{
				printf("Error ! Use only '>', '<', '='.\n");
				attempts--;
			}
			if (low > high && ans != '=')
			{
				printf("Error! Contradictory hints given.\n");
				break;
			}
		}
		printf("Number of attempts: %d\n", attempts);
		break;
	}

	}
	return 0;
}

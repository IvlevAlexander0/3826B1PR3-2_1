#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	int mode, x, i;
	i = 0;
	srand(time(NULL));

	printf("Choose mode\n");
	printf("1 - the programm guess\n");
	printf("2 - the human guess\n");
	if (scanf("%d", &mode) != 1)
	{
		printf("Invalid input\n");
		return 1;
	}

	if (mode == 1)
	{
		int a = 0;
		x = 1 + rand() % 1000;

		while (x != a)
		{
			printf("Enter the estimated number\n");
			if (scanf("%d", &a) != 1)
			{
				printf("Invalid input\n");
				return 1;
			}
			if (a < 1 || a > 1000)
			{
				printf("Number must be from 1 to 1000\n");
				a = 0;
				continue;
			}

			i++;

			if (x < a)
			{
				printf("The chosen number is smaller\n");
			}
			else if (x > a)
			{
				printf("The chosen number is greater\n");
			}
			else
			{
				printf("Guessed correctly!\n");
				printf("x = %d, a = %d, i = %d", x, a, i);
			}
		}

	}
	else if (mode == 2)
	{
		int left = 1, right = 1000;
		char c;

		printf("Guess a number from 1 to 1000\n");

		while (left <= right)
		{
			int a = (left + right) / 2;

			printf("Is this the number %d? (If the chosen number is smaller <; the chosen number is greater >; guessed correctly =): ", a);
			scanf(" %c", &c);
			if (scanf(" %c", &c) != 1)
			{
				printf("Invalid input\n");
				return 1;
			}

			if (c == '=')
			{
				i++;
				printf("Guessed correctly!\n");
				printf("a = %d, i = %d", a, i);
				return 0;
			}
			else if (c == '>')
			{
				left = a + 1;
				i++;
			}
			else if (c == '<')
			{
				right = a - 1;
				i++;
			}
			else
			{
				printf("Invalid input: please enter the specified characters\n");
			}
		}
		printf("Contradictory answers: no such number exists\n");
	}
	else
	{
		printf("Invalid mode\n");
	}

	return 0;
}
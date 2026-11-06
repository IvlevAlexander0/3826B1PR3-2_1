#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int n;
	int number[5];
	int guess[5];

	int i, j, digit, flag, guessNumber, temp, attempts = 0;

	printf("Enter the length (from 2 to 5) of the number you are trying to guess\n");
	if (scanf("%d", &n) != 1)
	{
		while (getchar() != '\n');
		n = 0;
	}

	if (n < 2 || n > 5)
	{
		printf("Wrong length!");
		return 0;
	}

	for (i = 0; i < n; i++)
	{
		do
		{
			digit = rand() % 10;
			flag = 0;

			if (i == 0 && digit == 0)
			{
				flag = 1;
			}

			for (j = 0; j < i; j++)
			{
				if (number[j] == digit)
					flag = 1;
			}

		} while (flag == 1);

		number[i] = digit;
	}


	while (1)
	{
		printf("Enter the number\n");
		printf("0-Throw in the towel\n");
		if (scanf("%d", &guessNumber) != 1)
		{
			while (getchar() != '\n');
			guessNumber = -1;
		}

		if (guessNumber == 0)
		{
			printf("The hidden number ");

			for (i = 0; i < n; i++)
			{
				printf("%d", number[i]);
			}

			break;
		}

		if (guessNumber < 0)
		{
			printf("Enter a positive number!\n");
			continue;
		}

		temp = guessNumber;
		int count = 0;

		while (temp > 0)
		{
			count++;
			temp /= 10;
		}

		if (count != n)
		{
			printf("U need to enter %d digits!\n", n);
			continue;
		}

		temp = guessNumber;

		for (i = n - 1; i >= 0; i--)
		{
			guess[i] = temp % 10;
			temp /= 10;
		}

		flag = 0;

		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (guess[i] == guess[j])
				{
					flag = 1;
				}
			}
		}

		if (flag == 1)
		{
			printf("Numbers must not be repeated!\n");
			continue;
		}

		attempts++;

		int bulls = 0;
		int cows = 0;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (number[i] == guess[j])
				{
					if (i == j)
					{
						bulls++;
					}
					else {
						cows++;
					}
				}
			}
		}

		printf("Bulls: %d\n", bulls);
		printf("Cows: %d\n", cows);

		if (bulls == n)
		{
			printf("U are win!\n");
			printf("Count of attempts = %d\n", attempts);
			break;
		}

	}
	

	return 0;
}
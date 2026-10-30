#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Md1()
{
	int a = rand();
	int n = (rand()*rand() % 1000) + 1;
	int guess;
	int c=1;
	printf("Programm generated random number in 1-1000 window, enter your guess:\n");
	scanf_s("%d", &guess);
	while (guess != n)
	{
		if (guess > 1000)
		{
			printf("Generated number is smaller than 1001\n");
		}
		else if (guess < 1)
		{
			printf("Generated number is bigger than 0\n");
		}
		else if (guess > n)
		{
			printf("Generated number is smaller than this\n");
		}
		else if (guess < n)
		{
			printf("Generated number is bigger than this\n");
		}
		scanf_s("%d", &guess);
		c = c + 1;
	
	}
	printf("You guessed the number!\nAmount of guesses = %d", c);
}
void Md2()
{
	int ver = 1000, niz = 1;
	char guess;
	int c=1,  n = 1+rand()%1000;
	printf("Pick your number in 1-1000 window, programm will try to guess it\nType '<' if your number is is smaller\nType '>' if your number is is bigger\nType '=' if programm guessed right\nGuessing number:\n");
	printf("You picked number: %d?\n", n);
	scanf_s(" %c", &guess);
	while (guess != '=')
	{
		if (guess == '>')
		{
			niz = n+1;
			if (ver > 1000 || niz < 1 || ver - niz < 0)
			{
				printf("You picked number not from the window or not natural number");
				return 0;
			}
			n = niz + rand() % (ver + 1 - niz);
			printf("You picked number: %d?\n", n);
		}
		else if (guess == '<')
		{
			ver = n-1;
			if (ver > 1000 || niz < 1 || ver - niz < 0)
			{
				printf("You picked number not from the window or not natural number");
				return 0;
			}
			n = niz + rand() % (ver + 1 - niz);
			printf("You picked number: %d?\n", n);

		}
		else
		{
			printf("You typed something wrong, try again\n");
		}
		scanf_s(" %c", &guess);
		c = c + 1;
	}
	printf("I guessed the number!\nAmount of guesses = %d", c);

}
int main()
{
	srand((unsigned int)time(NULL));
	printf("Choose the mode (enter numbers 1 or 2):\n1 - You guess the number\n2 - Progqramm guesses your number\n");
	int choice;
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		Md1();
	}
	else if (choice == 2)
	{
		Md2();
	}
	else
	{
		printf("Invalid mode");
		return 0;
	}
	return 0;
}
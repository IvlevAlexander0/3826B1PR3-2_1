#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>

void user() {
	int num = rand()%1000+1;
	int user_num, n = 0;

	do {
		printf("Try to guess. Enter your number.\n");
		if (scanf("%d", &user_num) != 1) {
			printf("Enter a valid number\n");
			return;
		}
		n++;
		if (user_num < num) {
			printf("The guessed number is greater.\n");
		}
		else if (user_num > num) {
			printf("The guessed number is less.\n");
		}
		else {
			printf("Hurray! The guessed number = %d\n", num);
			printf("Number of attempts = %d", n);
		}

	} while (user_num != num);

}
void computer() {
	int left = 1, right = 1000,n=0;
	char c;
	printf("Guess a number from 1 of 1000\n");
	while (left <= right) {
		int x = (left + right) / 2;
		printf("If this the number %d?\n",x);
		printf("If chosen number is smaller <;\n the chosen number is greater >;\n guessed correctle = :");
		
		if (scanf("%c", &c) != 1) {
			printf("Error\n");
			return;
		}
		n++;
		if (c == '=') {
			
			printf("Guessed correctly\n");
			printf("x= %d, n= %d", x, n);
			break;
		}
		else if (c == '>') {
			left = x + 1;
			
		}
		else if(c=='<'){
			right = x - 1;
			
		}
		else {
			printf("Please entter the specified characters\n");
		}

	}

}

int main() {

	srand(time(NULL));
	int choice;
	printf("Guess the number game from 1 to 1000\n");
	printf("Select the game mode\n");
	printf("0-You guess the number.\n");
	printf("1-The computer guesses your number.\n");
	
	if (scanf("%d", &choice) != 1) {
		printf("Error\n");
		return 1;
	}
	

	switch (choice) {
	case 0: user();
		break;
	case 1: computer();
		break;

	}
	return 0;
}
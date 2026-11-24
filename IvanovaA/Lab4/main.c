#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PRICE 10000
#define MAX_QTY 1000
#define N 100

int mstrlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

int mstrcomp(char str1[], char str2[])
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
		{
			return 0;
		}

		i++;
	}

	return 1;
}

void strcopy(char str[], int pos, char source[])
{
	int i = 0;

	while (source[i] != '\0')
	{
		str[pos + i] = source[i];
		i++;
	}
	str[pos + i] = '\0';
}

int checkbarcode(char code[])
{
	if (mstrlen(code) != 4)
	{
		return 0;
	}

	for (int i = 0; i < 4; i++)
	{
		if (code[i] < '0' || code[i] > '9')
		{
			return 0;
		}
	}
	return 1;
}

int compbarcode(char barcode[], int pos, char code[]) //////////////////
{
	for (int i = 0; i < 5; i++)
	{
		if (barcode[pos + i] != code[i])
		{
			return 0;
		}
	}
	return 1;
}

int findproduct(char barcode[], int count, char code[]) 
{
	for (int i = 0; i < count; i++)

	{
		if (compbarcode(barcode, i * 5, code))
		{
			return i;
		}
	}
	return -1;
}

int readint()
{
	char str[20];
	int num = 0;
	int i = 0;
	int sign = 1;
	int digits = 0;

	str[0] = '\0';
	if (scanf("%19s", str) != 1)
	{
		return -1;
	}

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return -1;
		}
		if (digits == 9)
		{
			return -1;
		}
		num = num * 10 + str[i] - '0';
		digits++;
		i++;
	}

	if (digits == 0)
	{
		return -1;
	}
	return num * sign;
}

void printname(char name[], int pos)
{
	int i = 0;
	while (name[pos + i] != '\0')
	{
		printf("%c", name[pos + i]);
		i++;
	}
}

void infproduct(char barcode[], char name[], int price[], int discount[], int k)
{
	printf("\n Name: ");
	printname(name, k * 101);

	printf("\n Barcode: ");

	for (int i = 0; i < 4; i++)
	{
		printf("%c", barcode[k * 5 + i]);
	}
	printf("\n Price: %d rub\n", price[k]);
	printf("Discount: %d%%\n", discount[k]);
}

void printcheck(char name[], int price[], int discount[], int check[], int quantity[], int size)
{
	int sum = 0;
	int discountsum = 0;

	if (size == 0)
	{
		printf("\nThe check is empty\n");
		return;
	}
	for (int i = 0; i < size; i++)
	{
		int k = check[i];
		int d = (price[k] * discount[k] + 50) / 100;
		int total = (price[k] - d) * quantity[i];

		printf("\nProduct: ");
		printname(name, k * 101);

		printf("\nPrice per unit: %d rub", price[k]);
		printf("\nQuantity: %d", quantity[i]);
		printf("\nDiscount: %d%%", discount[k]);
		printf("\nTotal cost: %d rub\n", total);

		sum += price[k] * quantity[i];
		discountsum += d * quantity[i];
	}

	printf("\nThe amount without a discount: %d rub\n", sum);
	printf("Total discount: %d rub\n", discountsum);
	printf("Total amount due: %d rub\n", sum - discountsum);
	printf("------------------------\n");
}

int main()
{
	char barcode[N * 5];
	char name[N * 101];
	int price[N];
	int discount[N];

	strcopy(barcode, 0, "1001");
	strcopy(barcode, 5, "1002");
	strcopy(barcode, 10, "1003");
	strcopy(barcode, 15, "1004");
	strcopy(barcode, 20, "1005");

	strcopy(name, 0, "Bread");
	strcopy(name, 101, "Cake");
	strcopy(name, 202, "Water");
	strcopy(name, 303, "Chocolate");
	strcopy(name, 404, "Milk");

	price[0] = 40;
	price[1] = 300;
	price[2] = 15;
	price[3] = 60;
	price[4] = 20;

	discount[0] = 10;
	discount[1] = 15;
	discount[2] = 5;
	discount[3] = 20;
	discount[4] = 10;

	int count = 5;

	int check[N];
	int quantity[N];
	int size = 0;
	int choice;
	char code[100];
	char tempname[101];

	while (1)
	{
		printf("\n-----Electronic cash register-----\n");
		printf("1. Add product\n");
		printf("2. Find product\n");
		printf("3. Add product in check\n");
		printf("4. Print the check\n");
		printf("5. Complete the purchase\n");

		choice = readint();

		if (choice == 1)
		{
			if (count == N)
			{
				printf("There is no space for new products\n");
				continue;
			}

			printf("Text the barcode: ");
			scanf("%99s", code);

			if (!checkbarcode(code))
			{
				printf("Incorrect barcode\n");
				continue;
			}
			if (findproduct(barcode, count, code) != -1)
			{
				printf("Such a barcode already exists\n");
				continue;
			}
			printf("Text the name of product: ");
			scanf(" %100[^\n]", tempname);

			int c;
			while ((c = getchar()) != '\n' && c != EOF)
			{

			}

			printf("Text the price: ");
			int p = readint();

			if (p <= 0 || p > MAX_PRICE)
			{
				printf("Incorrect price\n");
				continue;
			}

			printf("Text the discount(1-50): ");
			int d = readint();

			if (d < 1 || d > 50)
			{
				printf("Incorrect discount\n");
				continue;
			}

			strcopy(barcode, count * 5, code);
			strcopy(name, count * 101, tempname);
			price[count] = p;
			discount[count] = d;

			count++;

			printf("Product is added\n");
		}

		else if (choice == 2)
		{
			printf("Text the barcode: ");
			scanf("%99s", code);

			int k = findproduct(barcode, count, code);
			if (k == -1)
			{
				printf("The item was not found\n");
			}
			else
			{
				infproduct(barcode, name, price, discount, k);
			}
		}

		else if (choice == 3)
		{
			printf("Text the barcode : ");
			scanf("%99s", code);

			int k = findproduct(barcode, count, code);

			if (k == -1)
			{
				printf("The item was not found\n");
				continue;            
			}

			int found = 0;

			for (int i = 0; i < size; i++)
			{
				if (check[i] == k)
				{
					if (quantity[i] >= MAX_QTY)
					{
						printf("Too many unitf of this product\n");
						found = 2;
						break;
					}
					quantity[i]++;
					found = 1;
					break;
				}
			}
			if (found == 2)
			{
				continue;
			}

			if (found == 0)
			{
				if (size == N)       
				{
					printf("The check is full\n");
					continue;
				}
				check[size] = k;
				quantity[size] = 1;
				size++;
			}

			printf("The item was added to the check\n");

		}

		else if (choice == 4)
		{
			printcheck(name, price, discount, check, quantity, size);
		}

		else if (choice == 5)
		{
			if (size == 0)
			{
				printf("The check is empty. Add at least 1 product\n");
				continue;
			}
			printcheck(name, price, discount, check, quantity, size);
			printf("\n1.Start the new check\n");
			printf("0. Ñomplete the work\n");

			choice = readint();

			if (choice == 0)
			{
				break;
			}
			if (choice == 1)
			{
				size = 0;
				printf("A new check has been started\n");
			}
			else
			{
				printf("Incorrect choice\n");
			}
		}

		else
		{
			printf("Incorrect point of menu\n");
		}


	}




	return 0;
}
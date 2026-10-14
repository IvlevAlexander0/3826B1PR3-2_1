#include <stdio.h>
#include <math.h>
void main()
{
	printf("Enter your figure (pawn, king, queen, bishop, knight, rook) with numbers 1-6, position vertical A-H, horisontal 1-8 \nand square you want to move to the same way\n");
	char symb, sym1;
	int numb, num1, fig;
	scanf_s("%d", &fig);
	if (fig > 6 || fig < 1)
	{
		printf("Invalid figure");
		return 0;
	}
	scanf_s(" %c%d", &symb, 1, &numb);
	int symnum = symb - 'A' + 1;
	if (symnum > 8 || symnum < 1 || numb>8 || numb < 1)
	{
		printf("Invalid position");
		return 0;
	}
	scanf_s(" %c%d", &sym1, 1, &num1);
	int symn1 = sym1 - 'A' + 1;
	if (symn1 > 8 || symn1 < 1 || num1>8 || num1 < 1)
	{
		printf("Invalid move");
		return 0;
	}
	if (symn1 - symnum == 0 && num1 - numb == 0)
	{
		printf("You can't move to the same position you are on");
		return 0;
	}
	int p=0, ki=0, q=0, b=0, kn=0, r=0;
	if (symn1-symnum<2 && num1-numb==0)
	{
		p = 1;
		if (fig == p)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			p = 8;
		}
	}
	if (abs(symn1 - symnum) < 2 && abs(num1 - numb) < 2)
	{
		ki = 2;
		if (fig == ki)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			ki = 8;
		}
	}
	if (symn1 - symnum == 0 || num1 - numb == 0 ||(abs(symn1 - symnum) < 2 && abs(num1 - numb) < 2)|| (abs(symn1 - symnum) == abs(num1 - numb)))
	{
		q = 3;
		if (fig == q)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			q = 8;
		}
	}
	if (abs(symn1 - symnum) == abs(num1 - numb))
	{
		b = 4;
		if (fig == b)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			b = 8;
		}
	}
	if (abs(symn1 - symnum) ==2 && abs(num1 - numb) == 1 || abs(symn1 - symnum) == 1 && abs(num1 - numb) == 2)
	{
		kn = 5;
		if (fig == kn)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			kn = 8;
		}
	}
	if (symn1 - symnum == 0 || num1 - numb == 0)
	{
		r = 6;
		if (fig == r)
		{
			printf("Yes you can make this move");
			return 0;
		}
		else
		{
			r = 8;
		}
	}
	else if (p+ki+q+b+kn+r>0)
	{
		printf("No you can't make this move but:\n");
		if (p == 8)
			printf("pawn\n");
		if (ki == 8)
			printf("king\n");
		if (q == 8)
			printf("queen\n");
		if (b == 8)
			printf("bishop\n");
		if (kn == 8)
			printf("knight\n");
		if (r == 8)
			printf("rook\n");
		printf("Can make this move from that position");
	}
	else
	{
		printf("No figure is able to make this move");
	}
	return 0;
}

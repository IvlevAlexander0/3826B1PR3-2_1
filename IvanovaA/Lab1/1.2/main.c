#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int x1, x2, y1, y2;
	int figure;
	int dx, dy;

	printf("Enter the coordinate K1 (x1,y1)\n");
	scanf("%d%d", &x1, &y1);

	printf("Enter the coordinate K2 (x2,y2)\n");
	scanf("%d%d", &x2, &y2);

	printf("Choose the figure: \n");
	printf("1 - King\n");
	printf("2 - Queen\n");
	printf("3 - Rook\n");
	printf("4 - Bishop\n");
	printf("5 - Knight\n");
	printf("Your choice: \n");
	scanf("%d", &figure);

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);

	int moveKing = 0;
	int moveQuene = 0;
	int moveRook = 0;
	int moveBishop = 0;
	int moveKnight = 0;

	if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8 || x2 < 1 || x2 > 8 || y2 < 1 || y2 > 8)
	{
		printf("Error coordinates must be from 1 to 8\n");
		return;
	}
	if (x1 == x2 && y1 == y2)
	{
		printf("Error K1 and K2 are the same \n");
		return;
	}

	if (dx <= 1 && dy <= 1) moveKing = 1;
	if (x1 == x2 || y1 == y2) moveRook = 1;
	if (dx == dy) moveBishop = 1;
	if (moveRook == 1 || moveBishop == 1) moveQuene = 1;
	if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) moveKnight = 1;

	int moveFigure = 0;

	switch (figure)
	{
	case 1: moveFigure = moveKing; break;
	case 2: moveFigure = moveQuene; break;
	case 3: moveFigure = moveRook; break;
	case 4: moveFigure = moveBishop; break;
	case 5: moveFigure = moveKnight; break;
	default:
		printf("Error: choose an another number of figure\n");
		return;
	}

	if (moveFigure == 1)
	{
		printf("Figure can move from K1 to K2 in one move\n");
	}
	else {
		printf("This figure cant move like that but the others figures can\n");
	}

	int figire_can = 0;
	if (moveKing == 1 && figure != 1)
	{
		printf("King\n");
		figire_can = 1;
	}
	if (moveQuene == 1 && figure != 2)
	{
		printf("Quene\n");
		figire_can = 1;
	}
	if (moveRook == 1 && figure != 3)
	{
		printf("Rook\n");
		figire_can = 1;
	}
	if (moveBishop == 1 && figure != 4)
	{
		printf("Bishop\n");
		figire_can = 1;
	}
	if (moveKnight == 1 && figure != 5)
	{
		printf("Knight\n");
		figire_can = 1;
	}
	if (figire_can == 0)
	{
		printf("Nobody can do it in one move\n");
	}

}
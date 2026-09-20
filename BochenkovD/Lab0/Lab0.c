#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void) {
	double x1, y1, r1;
	double x2, y2, r2;
	double d;
	double eps = 1e-9;
	printf("input x1,y1,r1: ");
	scanf("%lf %lf %lf",&x1,&y1,&r1);
	printf("input x2,y2,r2: ");
	scanf("%lf %lf %lf",&x2,&y2,&r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	if (d == 0 && r1 == r2)
	{
		printf("The circles coincide\n");
	}
	else if (d == r1 + r2)
	{
		printf("They touch externally\n");
	}
	else if (d == fabs(r1 - r2))
	{
		printf("They touch internally\n");
	}
	else if (d > r1 + r2)
	{
		printf("They do not intersect (externally)\n");
	}
	else if (d < fabs(r1 - r2))
	{
		printf("They do not intersect (one inside the other)\n");
	}
	else 
	{
		printf("They intersect at two points\n");
	}
}
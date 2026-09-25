#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void main()
{
	
	double x1, y1, r1;
	double x2, y2, r2;
	printf("enter x1, y1, r1\n ");
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	printf("enter x2, y2, r2\n ");
	scanf("%lf %lf %lf", &x2, &y2,  &r2);
	double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1)*(y2 - y1));
	if (d < fabs(r1 - r2)) {
		printf("nor intersect");
	}
	if (d > (r1 + r2)) {
		printf("not intersect");
	}
	if (fabs(r1 - r2) < d && (r1 + r2) > d) {
		printf("intersect");
	}
	if (d == r1 + r2) {
		printf("touch");
	}
	if (d != 0 && d == fabs(r1 - r2)) {
		printf("touch");
	}
	if (d == 0 && r1 == r2) {
		printf("touch");
	}

}
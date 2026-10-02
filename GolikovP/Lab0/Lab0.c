#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"

void main()
{
	double x1, y1, r1;
	double x2, y2, r2;
	int check = 0;
	printf("Write the coordinates of center and radius of first cycle:");
	scanf("%lf %lf %lf", &x1, &y1, &r1);
	printf("Write the coordinates of center and radius of second cycle:");
	scanf("%lf %lf %lf", &x2, &y2, &r2);

	if (r1 < 0) {
		printf("Error");
	}
	if (r2 < 0) {
		printf("Error");
	}
	double path = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	double sum_r = r1 + r2;
	double min_r = sqrt(pow((r2 - r1), 2));

	if (x1 == x2 && y1 == y2 && r1 != r2 && check == 0) {
		printf("Circles have the same center");
		check = 1;
	}
	if (x1 == x2 && y1 == y2 && r1 == r2 && check == 0) {
		printf("Circles are the same");
		check = 1;
	}

	if (min_r < path && path < sum_r && check == 0) {
		printf("Overlaping");
		check = 1;
	} if (path = sum_r && path != min_r && check == 0) {
		printf("Tangency");
		check = 1;
	}  if (path = min_r && path != sum_r && check == 0) {
		printf("Tangency");
		check = 1;
	}

	if (check = 0) {
		printf("Not overlaping");
		check = 1;
	}
}
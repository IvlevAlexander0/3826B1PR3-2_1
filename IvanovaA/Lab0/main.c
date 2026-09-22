#include <stdio.h>
#include <math.h>

void main()
{
	double R1, R2, d;
	double x1, x2, y1, y2;

	printf("Write the radii of circles: R1 R2\n");
	scanf_s("%lf%lf", &R1, &R2);

	printf("Write the coordinates of the cetrer of the circles: x1, y1, x2, y2\n");
	scanf_s("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

	if ((R1 <= 0) || (R2 <= 0))
	{
		printf("Error\n");
	}
	else if ((d < 1e-12) && (R1 == R2))
	{
		printf("Coincide\n");
	}
	else if (d == R1 + R2)
	{
		printf("External touch\n");
	}
	else if (d == fabs(R1 - R2))
	{
		printf("Internal touch\n");
	}
	else if (d < fabs(R1 - R2))
	{
		printf("Not intersect one inside the other\n");
	}
	else if (d > R1 + R2)
	{
		printf("Not intersect outside\n");
	}
	else
	{
		printf("Intersect\n");
	}

}
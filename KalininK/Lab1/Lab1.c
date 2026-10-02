#include <stdio.h>
#include <math.h>
int main() {
	printf("Enter radius 1, radius 2, center 1 x, center 1 y, center 2 x, center 2 y");
	double r1, r2, x1, y1, x2, y2;
	scanf_s("%lf %lf %lf %lf %lf %lf", &r1, &r2, &x1, &y1, &x2, &y2);
	double rast = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	if (r1 < 0 || r2 < 0)
	{
		printf("Invalid radius");
	}
	else if (rast == r1 + r2)
	{
		printf("Touching outside eachother");
	}
	else if (rast > r1 + r2)
	{
		printf("Not touching");
	}
	else if ((rast+r1<r2 || rast+r2<r1) && rast > 0)
	{
		printf("One circle is inside the other");
	}
	else if ((rast + r1 == r2 || rast + r2 == r1) && (rast < r1 || rast < r2) && rast>0)
	{
		printf("One circle touching other from inside");
	}
	else if ((rast + r1 > r2 || rast + r2 > r1) && (rast<r1 || rast<r2) && rast>0)
	{
		printf("One circle overlaps with another from inside");
	}
	else if ((rast + r1 > r2 || rast + r2 > r1) && (rast == r1 || rast == r2) && rast > 0)
	{
		printf("One circle lies on circumference of the other");
	}
	else if (x1 == x2 & y1 == y2 & r1 != r2)
	{
		printf("Same center one circle inside the other");
	}
	else if (x1 == x2 & y1 == y2 & r1 == r2)
	{
		printf("Same circles");
	}
	else
	{
		printf("Overlaping outside eachother");
	}
	return 0;
}
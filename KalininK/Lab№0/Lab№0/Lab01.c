#include <stdio.h>
#include <math.h>
int main() {
	printf("Enter radius 1, radius 2, center 1 x, center 1 y, center 2 x, center 2 y");
	float r1, r2, x1, y1, x2, y2;
	scanf_s("%f %f %f %f %f %f", &r1, &r2, &x1, &y1, &x2, &y2);
	if (r1 < 0 | r2 < 0)
		printf("Invalid radius");
	else
	{
		if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) == r1 + r2)
			printf("Touching");
		else
		{
			if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) > r1 + r2)
				printf("Not touching");
			else
			{
				if (x1 == x2 & y1 == y2 & r1 != r2)
					printf("Same center");
				else
				{
					if (x1 == x2 & y1 == y2 & r1 == r2)
						printf("Same circles");
					else
					{
						printf("Overlaping");
					}
				}
				
			}
		}
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	double h, d, w, m;
	int n;
	double den_dsp, den_dvp, den_wood;


	printf("Enter the height (180-220)\n");
	scanf("%lf", &h);
	printf("Enter the width (80-120)\n");
	scanf("%lf", &w);
	printf("Enter the depth (50-90)\n");
	scanf("%lf", &d);

	if (h < 180 || h > 220)
	{
		printf("Error\n");
		return 0;
	}

	if (w < 80 || w > 120)
	{
		printf("Error\n");
		return 0;
	}

	if (d < 50 || d > 90)
	{
		printf("Error\n");
		return 0;
	}

	printf("Enter the density of dsp\n");
	scanf("%lf", &den_dsp);
	printf("Enter the density of dvp\n");
	scanf("%lf", &den_dvp);
	printf("Enter the density of wood\n");
	scanf("%lf", &den_wood);

	n = (int)(h / 40);
	if (n * 40 == h)
	{
		n--;
	}

	double v_dsp = 2 * h/100 * d/100 * 0.015 + 2 * w/100 * d/100 * 0.015 + n * (w-3)/100 * d/100 * 0.005;
	double v_dvp = h/100 * w/100 * 0.005;
	double v_wood = h/100 * w/100 * 0.01;

	m = v_dsp * den_dsp + v_dvp * den_dvp + v_wood * den_wood;

	printf("Mass of the wardrobe = %lf", m);

	return 0;
}
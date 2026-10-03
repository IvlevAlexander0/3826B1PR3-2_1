#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	const double dsp = 550, dvp = 800, tree = 400;
	double h, d, w;
	printf("Enter the height, depth, width: ");
	scanf("%lf%lf%lf", &h, &d, &w);
	if (h < 180 || h > 220 || d < 50 || d > 90 || w < 80 || w > 120)
	{
		printf("Error");
	}
	else 
	{
		double h_m = h / 100.0;
		double w_m = w / 100.0;
		double d_m = d / 100.0;
		double back = dvp * h_m * w_m * 0.005;
		double sides = 2 * (dsp * h_m * d_m * 0.015);
		double caps = 2 * (dsp * w_m * d_m * 0.015);
		double doors = tree * h_m * w_m * 0.01;
		int num_shelves = (int)((h - 3.0) / 40.0);
		double inner_width = w_m - 2 * 0.015;
		double v_one_shelf = inner_width * d_m * 0.005;
		double shelves = num_shelves * v_one_shelf * dsp;
		double total_mass = back + sides + caps + doors + shelves;
		printf("%lf", total_mass);
	}
}
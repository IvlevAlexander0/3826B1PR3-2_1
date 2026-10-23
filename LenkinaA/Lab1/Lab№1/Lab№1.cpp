#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void main() {
	double dvp = 850;//плотность двп
	double dsp = 700;//плотность дсп
	double tree = 650;//плотность дерева
	
	
	double h_cm,w_cm,d_cm; // высота,ширина и глубина в см
	printf("Enter the height, width, and depth in cm.\n");
	scanf("%lf %lf %lf", &h_cm, &w_cm, &d_cm);
	
	if ((180 > h_cm || h_cm > 220) || (80 > w_cm || w_cm > 120) || (50 > d_cm || d_cm > 90)) {
		printf("error");
	}
	else {
		double h = h_cm / 100;
		double w = w_cm / 100;
		double d = d_cm / 100;

		int n;
		n = (int)(h / 40);
		if (n * 40 == h) {
			n--;
		}
		double V_dvp = h * w * 0.005;
		double V_dsp = 2 * h * d * 0.015 + 2 * w * d * 0.015 + n * (w_cm - 3) / 100 * d * 0.005;
		double V_tree = h * w * 0.01;

		double mass = V_dsp * dsp + V_dvp * dvp + V_tree * tree;
		printf("the mass of the cabinet= %lf", mass);
	}
}



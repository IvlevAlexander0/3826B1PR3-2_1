#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void main() {
	double dvp = 850;//плотность двп
	double dsp = 700;//плотность дсп
	double tree = 650;//плотность дерева
	
	double t_sides = 0.015;// толщина зад.стенки в м.
	double t_b_wall = 0.005;// толщина боковины в м.
	double t_b_t_cap = 0.015;// толщина крашки в м.
	double t_door = 0.001;// толщина двери в м.
	double t_shelves = 0.005;// толщина полки в м.
	

	double h_cm,w_cm,d_cm; // высота,ширина и глубина в см
	printf("Enter the height, width, and depth in cm.\n");
	scanf("%lf %lf %lf", &h_cm, &w_cm, &d_cm);
	
	if ((180 <= h_cm && h_cm <= 220) && (80 <= w_cm && w_cm <= 120) && (50 <= d_cm && d_cm <= 90)) {
		double h = h_cm / 100;
		double w = w_cm / 100;
		double d = d_cm / 100;

		double back = (h * w * t_sides) * dvp;
		double b_wall = (2 * (w * d * t_b_wall)) * dsp;
		double caps = (2 * (w * d * t_b_t_cap)) * dsp;
		double doors = (h * w * t_door) * tree;

		int num = (int)(h / 0.4) - 1;
		if (num < 0) {
			num = 0;
		}
		double shelves = (num * ((w - (2 * t_b_wall)) * d * t_shelves)) * dsp;

		double mass = back + b_wall + caps + doors + shelves;
		printf("the mass of the cabinet= %lf", mass);
	}
	else {
		printf("error");
	}
}



#include "stdio.h"
int main()
{
	double h, d, w;
	double dsp = 600.0;
	double dvp = 850.0;
	double tree = 400.0;
	printf_s("enter the height, width, and depth");
	if (scanf_s("%lf %lf %lf", &h, &d, &w) != 3) {
		printf_s("error\n");
	}
	if ((h >= 180 && h <= 220) || (w >= 80 && w <= 120) || (d >= 50 && d <= 90)) {
		printf_s("error\n");
	}
	double h_m = h / 100.0;
	double w_m = w / 100.0;
	double d_m = d / 100.0;

	double m_back = dvp * (h_m * w_m * 0.005); //1. back wall 
	double m_side = dsp * (h_m * d_m * 0.015) * 2; //2. side walls
	double m_top = dsp * (w_m * d_m * 0.015) * 2; //3. upper and lowers walls
	double m_door = tree * (h_m * w_m * 0.01); //4. doors

	int num = (int)(h / 40.0) - 1;
	if (num < 0) {
		num = 0;
	}
	double shelf_m = (w - 2 * 0.15) / 100.0; //5. shelves
	double shelf_d = d_m;
	double m_shelf = 0;
	if (num > 0) {
		m_shelf = dsp * (shelf_m * shelf_d * 0.005) * num;
	}
	double M = m_back + m_side + m_top + m_door + m_shelf;

	printf_s("the mass of tne cabinet is:%.21f kg\n", M);
}
#include <stdio.h>

void main() {
	double h, w, m1;
	printf("enter the height and width of the back panel (sm)\n");
	printf("height:");
	scanf_s("%lf", &h);
	printf("widht:");
	scanf_s("%lf", &w);
	if (h >= 180 && h <=  220 && w >= 80 && w <= 120) {
		m1 = (h * w * 0.5) * 0.9;
	}
	else {
		printf("error");
		return 1;
	}

	double  d, m, m2, m3, m4, m5;
	printf("\nenter the depth of one of the wardrobe side panels (sm)\n");
	printf("depth:");
	scanf_s("%lf", &d);
	if (d >= 50 && d <= 90) {
		m2 = (h * d * 1.5) * 2 * 0.65;
	}
	else {
		printf("error");
		return 1;
	}

	m3 = (w * d * 1.5) * 2 * 0.65;
	m4 = h * w * 0.55;
	m5 = (w - (2 * 1.5)) * d * 0.5 * 0.65 * ((int)h / 40);
	printf("\nweight: %.2lf kg\n", m = (m1 + m2 + m3 + m4 + m5) / 1000);
	return 0;
}
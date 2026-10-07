#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    double h, d, w;
    int Ppa = 550;
    int Pfi = 850;
    int Pwo = 600;
    printf("Enter the wardrobe height in centimeters (between 180 and 220). \n");
    scanf("%lf", &h);
    printf("Enter the wardrobe depth in centimeters (from 50 to 90). \n");
    scanf("%lf", &d);
    printf("Enter the cabinet width in centimeters (from 80 to 120). \n");
    scanf("%lf", &w);
    if ((h < 180 || h > 220) || (d < 50 || d > 90) || (w < 80 || w > 120)) {
        printf("Error: The parameters exceed the established limits.");
    }
    else {
        int Ns = h / 40;
        double bp = h * w * 0.5;
        double sp = 2 * h * d * 1.5;
        double lids = 2 * d * w * 1.5;
        double doors = h * w;
        double is = Ns * (w - (1.5 + 1.5)) * d * 0.5;
        double m = ((((sp + lids + is) * Ppa) + (bp * Pfi) + (doors * Pwo)) / 1000000);
        printf("The mass of the cabinet is equal to %lf", m);
        printf(" kilograms.");
    }
}
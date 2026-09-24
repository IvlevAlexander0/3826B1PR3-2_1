#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void main()
{
    double r1;
    double r2;
    double x1;
    double y1;
    double x2;
    double y2;
    printf("Enter the radius of the first circle: \n");
    scanf("%lf", &r1);
    printf("Enter the radius of the second circle: \n");
    scanf("%lf", &r2);
    printf("Enter the x-coordinate of the center of the first circle: \n");
    scanf("%lf", &x1);
    printf("Enter the y-coordinate of the center of the first circle: \n");
    scanf("%lf", &y1);
    printf("Enter the x-coordinate of the center of the second circle: \n");
    scanf("%lf", &x2);
    printf("Enter the y-coordinate of the center of the second circle: \n");
    scanf("%lf", &y2);
    double d;
    d = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    const double eps = 1e-9;
    if ((r1 <= eps) || (r2 <= eps)) {
        printf("The radius cannot be negative");
    }
    else {
        if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {
            printf("the circles coincide");
        }
        else {
            if ((d == (r1 + r2)) || (d == fabs(r1 - r2))) {
                printf("concern");
            }
            else {
                if ((d > (r1 + r2)) || (d < fabs(r1 - r2))) {
                    printf("do not overlap");
                }
                else {
                    if (((r1 - r2) < d) && (d < (r1 + r2))) {
                        printf("intersect");
                    }
                    else {
                        printf("Error");
                    }
                }
            }
        }
    }
}
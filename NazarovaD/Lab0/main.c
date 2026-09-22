#include "stdio.h"

void main()
{
    double x1, y1, r1;
    double x2, y2, r2;
    scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &x2, &y1, &y2, &r1, &r2);
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (d < fabs(r1 - r2)) {
        printf_s("not intersect1");
    }
    if (fabs(r1 - r2) < d && (r1 + r2) > d) {
        printf_s("intersect2");
    }
    if (d == r1 + r2) {
        printf_s("touch3");
    }
    if (d == fabs(r1 - r2) && d != 0) {
        printf_s("touch4");
    }
    if (d > (r1 + r2)) {
        printf_s("not intersect5");
    }
    if (d == 0 && r1 == r2) {
        printf_s("touch6");
    }
}
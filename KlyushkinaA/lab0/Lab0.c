
#include <stdio.h>
#include <math.h>

void main() {
    double x1, y1;
    double x2, y2;
    double r1;
    double r2;
    printf("enter x1, y1, x2, y2, r1, r2 \n");
    scanf_s("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r1, &r2);
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (d == 0 && r1 == r2) {
        printf("coincide\n");
    }
    else if (d > r1 + r2) {
        printf("dont intersect\n");
    }
    else if (d < fabs(r1 - r2)) {
        printf("dont intersect\n");
    }
    else if (d == r1 + r2) {
        printf("tangent\n");
    }
    else if (d == fabs(r1 - r2)) {
        printf("tangent\n");
    }
    else if ((fabs(r1 - r2) < d) && (d < (r1 + r2))) {
        printf("intersect\n");
    }
}
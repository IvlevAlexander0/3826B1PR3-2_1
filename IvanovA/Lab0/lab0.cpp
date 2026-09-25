#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1;
    double x2, y2, r2;

    printf("Enter x1, y1, r1: ");
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    printf("Enter x2, y2, r2: ");
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    if (r1 <= 0 || r2 <= 0) {
        printf("Error");
        return 0;
    }

    double center = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double sum = r1 + r2;
    double diff = fabs(r1 - r2);

    if (center == 0 && r1 == r2) {
        printf("Circles match\n");
    }
    else if (center == 0) {
        printf("Concentric, do not touch\n");
    }
    else if (center < diff) {
        printf("One inside another, do not touch\n");
    }
    else if (center == diff) {
        printf("Internal touch\n");
    }
    else if (center < sum) {
        printf("Intersect\n");
    }
    else if (center == sum) {
        printf("External touch\n");
    }
    else {
        printf("Doent touch, outside each other\n");
    }
    return 0;
}
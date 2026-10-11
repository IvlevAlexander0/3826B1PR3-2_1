#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double h, w, d, r1 = 850.0, r2 = 700.0, r3 = 650.0;
    printf("insert h, w, d: ");
    if (scanf("%lf%lf%lf", &h, &w, &d) != 3) {
        printf("Error");
        return 0;
    }
    if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90) {
        printf("Error");
        return 0;
    }

    double H = h / 100, W = w / 100, D = d / 100;
    int n = (int)((h - 3.0) / 40.0);

    double m_dvp = H * W * 0.005 * r1;
    double m_dsp = (2 * H * D * 0.015 + 2 * W * D * 0.015 + n * (w - 3.0) / 100 * (d - 1.5) / 100 * 0.005) * r2;
    double m_wood = H * W * 0.010 * r3;

    printf("%d\n%.2f\n", n, m_dvp + m_dsp + m_wood);
    return 0;
}
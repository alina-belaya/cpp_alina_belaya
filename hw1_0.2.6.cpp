#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    double a, b, c, r;

    printf("Angle degree 1: ");
    scanf("%lf", &a);

    printf("Angle degree 2: ");
    scanf("%lf", &b);

    c = 180 - (a + b);

    printf("Radius: ");
    scanf("%lf", &r);

    double s = 2 * r * r * sin(a) * sin(b) * sin(c);
    printf("Answer: %lf\n", s);
}

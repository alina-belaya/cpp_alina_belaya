#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

int main()
{
    int r, h;

    printf("Radius: ");
    scanf("%d", &r);

    printf("Height: ");
    scanf("%d", &h);

    const double PI = acos(-1.0);
    double v = PI * r * r * h;

    printf("V = %lf\n", v);
}
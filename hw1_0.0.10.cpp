#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    double a, t, v;

    printf("a:");
    scanf("%lf", &a);

    printf("t:");
    scanf("%lf", &t);

    printf("v:");
    scanf("%lf", &v);

    double s = (a * t * t) / 2;
    double t1 = v / a;

    printf("Path after t seconds: %lf\nTime when will be speed V: %lf\n", s, t1);
}

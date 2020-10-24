#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

double my_power(double x, int k)
{
    double X = x;
    for (int i = 1; i < k; i++)
        X *= x;
    return X;
}

int main()
{
    int k;
    double x;

    printf("k = ");
    scanf("%d", &k);

    printf("x = ");
    scanf("%lf", &x);

    double ans = my_power(x, k)/k;

    printf("ans: %lf\n", ans);
}

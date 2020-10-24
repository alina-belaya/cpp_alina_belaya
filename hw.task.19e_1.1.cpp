#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

double isReLu(int a, int x) {
    double res = x / (sqrt(1 + a * x * x));
    if (x >= 0) { return x; }
    else { return res; }
}

int main()
{
    int a, x;

    printf("a x = ");
    scanf("%d %d", &a, &x);

    double ans = isReLu(a, x);
    printf("%lf\n", ans);
}
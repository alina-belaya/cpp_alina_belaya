#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

double my_pow(int x, int y)
{
    double p = x;
    for (int i = 1; i < y; i++)
        p *= x;
    return p;
}

double my_multi(int k) {
    double ak = 1 / (my_pow(k, k) + 1);
    if (k == 1) return 1;
    return ak * my_multi(k - 1);
}

int main()
{
    int k;
    double a1 = 1.0;

    printf("k: ");
    scanf("%d", &k);

    double ans = my_multi(k);

    printf("ans = %lf\n", ans);
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int n, i;

    printf("n = ");
    scanf("%d", &n);

    int res = 1;
    for (i = n; i >= 2; i -= 2) res *= i;

    printf("n!! = %d\n", res);
}
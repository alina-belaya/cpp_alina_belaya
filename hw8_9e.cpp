#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<cmath>

bool Prim(int n) {
    for (int d = 2; d <= n / 2; d++)
        if (n % d == 0)
            return false;
    return true;
}

int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);

    int* arr = new int[n];
    int i;
    int pr = 0;

    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (Prim(arr[i]))
            pr++;
    }
    printf("how many prime numbers: %d\n", pr);
}
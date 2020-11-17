#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x;
    printf("x = ");
    scanf("%d", &x);

    int count = 0;

    while (x)
    {
        if (x & 1)  count++;
        x = (x >> 1);
    }
    printf("ans = %d\n", count);
}
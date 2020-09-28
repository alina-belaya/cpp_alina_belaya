#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int x;
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("x: ");
    scanf("%d", &x);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += pow(x, i*i);
    }
    printf("answer: %d\n", sum);
}
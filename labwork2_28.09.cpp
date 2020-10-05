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
    for (int i = 0; i < n; i++) {
        sum += pow(x, i);
    }
    printf("answer: %d\n", sum);
}
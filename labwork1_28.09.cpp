#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int n;
    double x;
    printf("n: ");
    scanf("%d", &n);
    printf("x: ");
    scanf("%lf\n", &x);
    for (int i = 0; i < n; i++) {
        x = sin(x);
    }
    printf("answer: %lf\n", x);
}

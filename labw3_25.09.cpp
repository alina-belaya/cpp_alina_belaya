#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int a, b, c;
    int d;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    d = b * b - 4 * a * c;
    if (d > 0) {
        printf("two solutions\n");
    }
    else if (d == 0) {
        printf("one solution\n");
    }
    else {
        printf("no solutions\n");
    }
}

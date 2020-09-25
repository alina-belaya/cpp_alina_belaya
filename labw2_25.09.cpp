#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    if (n % 10 != 0) {
        printf("false\n");
    }
    else {
        printf("true\n");
    }

    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    if (x - y >= 6) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }

}

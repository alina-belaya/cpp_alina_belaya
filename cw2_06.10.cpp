#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int n;

    printf("n = ");
    scanf("%d", &n);
    int x = n * 2;

    for (int i = 2; i <= x; i++) {
        int k = 0;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                k++;
                break;
            }
        }
        if (k == 0) { printf("%d ", i); }
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{
    int n;

    printf("N: ");
    scanf("%d", &n);
    printf("%d! = ", n);
    int i = 1;
    printf("%d", i);
    while (i<n) {
        i++;
        printf("*%d", i);
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int summCheck(int n, int x) {
    int summ = 0;
    do {
        summ += (x % 10);
        x = x / 10;
    } while (x > 0);
    if (summ == n) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int n, count = 0;

    printf("Input n: ");
    scanf("%d", &n);

    for (int i = 100; i <= 999; i++) {
        if (summCheck(n, i)) { 
            count++;
        }
    }

    printf("Result: %d numbers\n", count);
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int n, a1 = 0, a2 = 1, a_k, sum = a1 + 2 * a2, i = 4;

    printf("n = ");
    scanf("%d", &n);

    if (n == 1) {
        printf("Answer: %d\n", a1);
    } else if (n == 2){
        printf("Answer: %d\n", sum);
    }
    else {

        for (int k = 3; k <= n; k++) {
            a_k = a2 + k * a1;
            a1 = a2;
            a2 = a_k;
            i *= 2;
            sum += i * a_k;
        }
        printf("Answer: %d\n", sum);
    }
}


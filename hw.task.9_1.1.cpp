#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
    int R, a, b, c;

    printf("r = ");
    scanf("%d", &R);

    printf("a b c = ");
    scanf("%d %d %d", &a, &b, &c);
    
    int r = abs(R);

    if (r > a) {
        if (r > b && r > b + c * c) {
            printf("six dots");
        }
        else if (r == b) {
            printf("three dots");
        }
        else if (r == b + c * c || r < b + c * c) {
            printf("four dots");
        }
        else if (r < b) {
            printf("two dots");
        }
    }
    else if (r == a) {
        if (r > b && r > b + c * c) {
            printf("five dots");
        }
        else if (r == b) {
            printf("two dots");
        }
        else if (r == b + c * c) {
            printf("four dots");
        }
        else if (r < b + c * c) {
            printf("three dots");
        }
        else if (r < b) {
            printf("one dots");
        }
    }
    else if (r < a) {
        if (r > b && r > b + c * c) {
            printf("four dots");
        }
        else if (r == b) {
            printf("one dots");
        }
        else if (r == b + c * c) {
            printf("three dots");
        }
        else if (r < b) {
            printf("zero dots");
        }
        else if (r < b + c*c) {
            printf("two dots");
        }
    }
}
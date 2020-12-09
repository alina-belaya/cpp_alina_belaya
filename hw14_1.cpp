#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef
struct Date {
    unsigned int day;
    unsigned int mon;
    int year;
} Date;

int input(Date* x) {
    Date res;
    printf("day: ");
    scanf("%u", &res.day);

    printf("mon: ");
    scanf("%u", &res.mon);

    printf("year: ");
    scanf("%d", &res.year);

    *x = res;
    return 0;
}

void output(const Date x) {
    printf("day.month.year = %u.%u.%d\n", x.day, x.mon, x.year);
}

int main() {
    Date x;
    input(&x);
    output(x);
}
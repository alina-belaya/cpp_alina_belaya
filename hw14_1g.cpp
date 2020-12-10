#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef
struct Address {
    char city[25];
    char street[25];
    char house_num[10];
    unsigned int apartment_num;

} Address;

int input(Address* x) {
    Address res;
    printf("city: ");
    scanf("%s", &res.city);

    printf("street: ");
    scanf("%s", &res.street);

    printf("house number: ");
    scanf("%s", &res.house_num);

    printf("apartment number: ");
    scanf("%u", &res.apartment_num);

    *x = res;
    return 0;
}

void output(const Address x) {
    printf("Address is %s street %s, %u. %s\n", x.street, x.house_num, x.apartment_num, x.city);
}

int main() {
    Address x;
    input(&x);
    output(x);
}
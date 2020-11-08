#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x1 = -99, x2 = -99, x3 = -99, xn, count = 0;
	
	do {
		xn = x3 + x1 + 100;
		x3 = xn;
		x1 = x2;
		count++;
	} while (xn <= 0);
	
	printf("Answer: x[%d] = %d > 0\n", count+3, xn);
}
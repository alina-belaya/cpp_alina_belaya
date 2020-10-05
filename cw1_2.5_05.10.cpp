#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int factorial(int i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}

int main()
{
	int n, i, res;

	printf("n = ");
	scanf("%d", &n);
	printf("n! = %d\n", factorial(n));
}

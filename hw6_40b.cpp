#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long double fact(int n) {
	if (n == 0) { return 1; }
	else { return n * fact(n - 1); }
}

int main() {

	int n;
	double u, v;
	double ak, bk, sum, t;

	sum = 1;
	t = 1.0;

	printf("n = ");
	scanf("%d", &n);

	printf("u = ");
	scanf("%lf", &u);

	printf("v = ");
	scanf("%lf", &v);

	for (int k = 2; k <= n; k++) {
		ak = 2 * v + u;
		bk = 2 * u * u + v;

		u = ak;
		v = bk;

		sum += ak * bk / fact(k+1);
	}

	printf("sum = %lf\n", sum);
}
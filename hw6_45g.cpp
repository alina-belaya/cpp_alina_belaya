#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {

	double x, eps;
	double t, y;

	do {
		printf("x = ");
		scanf("%lf", &x);
	} while (fabs(x) > 1);

	do {
		printf("eps = ");
		scanf("%lf", &eps);
	} while (eps <= 0);

	t = 1;
	int znak = 1;
	y = 1;

	while (fabs(t) >= eps) {
		znak = -znak;
		t *= x;
		y += znak*t;
	}

	printf("y = %lf\n", y);
	printf("ans = %lf\n", 1/(1+x));
}
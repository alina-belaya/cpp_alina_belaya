#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

float machine_zero(float e, int& k)
{
    float e1;
    k = 0;

    do {
        e /= 2.0;
        e1 = e + 1.0;
        k++;
    } while (e1 > 1.0);

    return e;
}

int main()
{
    int k = 0;

    float f_e = machine_zero((float)1.0, k);
    cout << "Answer: " << f_e << endl;
}
#include <iostream> 
#include "ComplexPoly_BelayaAlina.h"
using namespace std;

int main()
{
	Polynomial a, b, c, t, d1, d2;

	Complex c1(5, 3);

	cout << "Complex num 1:" << endl;
	c1.print();

	a.enterTerms();
	b.enterTerms();

	t = a;
	cout << "\nPolynomial A is:\n";
	a.printPolynomial();

	cout << "Polynomial B is:\n";
	b.printPolynomial();

	cout << "\nA + B:\n";
	c = a + b;
	c.printPolynomial();

	cout << "\nA - B:\n";
	a = t;
	c = a - b;
	c.printPolynomial();

	cout << "\nA * B:\n";
	a = t;
	c = a * b;
	c.printPolynomial();

	cout << "\nA / B:\n";
	a = t;
	c = a / b;
	c.printPolynomial();

	cout << "\nA % Bs:\n";
	a = t;
	c = a % b;
	c.printPolynomial();

	cout << "\nDerivative:\n";
	d1 = a.derivative();
	d1.printPolynomial();

	double x;
	cout << "\nInput x:" << endl;
	cin >> x;

	cout << "Value of A in x: ";
	a.value(x);

	cout << endl;
}

#ifndef COMPLEXPOLY_BELAYAALINA_H
#define COMPLEXPOLY_BELAYAALINA_H
#include <iostream>
#include <vector>
#include <complex>
using namespace std;

class Complex
{
public:
	Complex(double r = 0, double i = 0);
	double real() const;
	double imag() const;
	void print(ostream&) const;
	Complex operator+(Complex);
	Complex operator-(Complex);
	Complex operator*(Complex);
	Complex operator^(int);
	friend ostream& operator<<(ostream&, const Complex&);
private:
	double im;
	double re;
};

class Polynomial
{
public:
	Polynomial();
	Polynomial(Complex*, int);
	Polynomial operator+(const Polynomial&) const; // оператор додавання
	Polynomial operator-(const Polynomial&) const; // оператор віднімання
	Polynomial operator*(const Polynomial&) const;
	Polynomial& operator=(const Polynomial&); // оператор присвоєння
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial derivative();
	Complex value(Complex);
	void printPolynomial(ostream&) const;
	~Polynomial();
	friend ostream& operator<<(ostream&, const Polynomial&);

private:
	int numberOfTerms;
	Complex* coefficients;
};

#endif
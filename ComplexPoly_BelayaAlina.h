#ifndef COMPLEXPOLY_BELAYAALINA_H
#define COMPLEXPOLY_BELAYAALINA_H
#include <iostream>
using namespace std;

class Complex
{
	public:
		Complex(double r = 0, double i = 0);
		double real() const;
		double imag() const;
		void print() const;
		Complex operator+(Complex);
		Complex operator*(Complex);
		Complex operator^(int);
	private:
		double im;
		double re;
};

class Polynomial
{
public:
	static const int maxTerms = 100; // максимальна кількість доданків у багаточлені

	Polynomial();
	Polynomial operator+(const Polynomial&) const; // оператор додавання
	Polynomial operator-(const Polynomial&) const; // оператор віднімання
	Polynomial operator*(const Polynomial&) const; // оператор множення
	Polynomial operator/(const Polynomial&) const; // оператор ділення
	Polynomial operator%(const Polynomial&) const; // оператор ділення з остачею
	Polynomial& operator=(const Polynomial&); // оператор присвоєння
	Polynomial& operator+=(const Polynomial&);
	Polynomial& operator-=(const Polynomial&);
	Polynomial& operator*=(const Polynomial&);
	Polynomial& operator/=(const Polynomial&);
	void enterTerms();
	void printPolynomial() const;
	void value(double) const;
	Polynomial& derivative() const;
	int getNumberOfTerms() const;
	int getTermExponent(int) const;
	double getTermCoefficient(int) const;
	void setCoefficient(int, double);
	~Polynomial();

private:
	char arr[maxTerms];
	int numberOfTerms;
	int exponents[maxTerms];
	double coefficients[maxTerms];
	static void similarTerms(Polynomial&);
};

#endif

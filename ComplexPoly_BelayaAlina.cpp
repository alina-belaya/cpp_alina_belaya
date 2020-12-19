#include <iostream>
#include "ComplexPoly_BelayaAlina.h"
using namespace std;

Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}

// дійсна частина комплексного числа
double Complex::real() const
{
    return re;
}

// уявна частина комплексного числа
double Complex::imag() const
{
    return im;
}

// вивід комплексного числа 
void Complex::print(ostream& out) const
{
    out << "(" << re << showpos << im << noshowpos << "i)";
}

//оператор додавання комплексних чисел
Complex Complex::operator+(Complex c2)
{
    Complex res(re + c2.real(), im + c2.imag());
    return res;
}

//оператор віднімання комплексних чисел
Complex Complex::operator-(Complex c2)
{
    Complex res(re - c2.real(), im - c2.imag());
    return res;
}

//оператор множення комплексних чисел
Complex Complex::operator*(Complex c2)
{
    double r = re * c2.real() - im * c2.imag();
    double i = re * c2.imag() + im * c2.real();
    Complex res(r, i);
    return res;
}

//оператор піднесення до степеня комплексних чисел
Complex Complex::operator^(int power)
{
    if (power == 0)
        return Complex(1, 0);

    Complex res = *this;

    for (int i = 1; i < power; ++i)
        res = res * (*this);
    return res;
}

ostream& operator<<(ostream& out, const Complex& cp) {
    cp.print(out);
    return out;
}

//створення порожнього массиву коефіцієнтів для подальшого заповнення
Polynomial::Polynomial()
{
    coefficients = nullptr;
    numberOfTerms = 0;
}

//заповнення массиву коефіцієнтів
Polynomial::Polynomial(Complex* coeffs, int n)
{
    coefficients = new Complex[n];
    numberOfTerms = n;
    for (int i = 0; i < n; i++) coefficients[i] = coeffs[i];
}

// вивід поліному
void Polynomial::printPolynomial(ostream& out) const
{
    if (numberOfTerms == 0)
        cout << '0' << endl; //вивести 0, якщо не були введені коефіцієнти

    for (int i = numberOfTerms - 1; i > 0; i--)
        out << coefficients[i] << "x^" << i << " + ";
    out << coefficients[0];
}

// оператор присвоєння 
Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this == &other)
        return *this;
    else
    {
        delete[] coefficients;
        coefficients = new Complex[other.numberOfTerms];
        numberOfTerms = other.numberOfTerms;

        for (int i = 0; i < numberOfTerms; i++)
            coefficients[i] = other.coefficients[i];
    }

    return *this;
}

// оператор додавання
Polynomial Polynomial::operator+(const Polynomial& other) const
{
    int maxOfTerms; //старший коефіцієнт
    if (other.numberOfTerms > numberOfTerms)
        maxOfTerms = other.numberOfTerms;
    else
        maxOfTerms = numberOfTerms;

    Complex* poly_coeff = new Complex[maxOfTerms];
    Complex zero(0, 0);

    for (int i = 0; i < maxOfTerms; i++)
    {
        poly_coeff[i] = zero;
        poly_coeff[i] = poly_coeff[i] + (coefficients[i]);
        if (i < other.numberOfTerms)
            poly_coeff[i] = poly_coeff[i] + (other.coefficients[i]);
    }

    /*for (int i = 0; i < maxOfTerms; i++)
    {
        cout << "poly_coeff[i] " << poly_coeff[i] << endl;
    }*/

    Polynomial poly(poly_coeff, maxOfTerms);

    return poly;
}

// оператор віднімання
Polynomial Polynomial::operator-(const Polynomial& other) const
{
    int maxOfTerms; //старший коефіцієнт
    if (other.numberOfTerms > numberOfTerms)
        maxOfTerms = other.numberOfTerms;
    else
        maxOfTerms = numberOfTerms;

    Complex* poly_coeff = new Complex[maxOfTerms];
    Complex zero(0, 0);

    for (int i = 0; i < maxOfTerms; i++)
    {
        poly_coeff[i] = zero;
        poly_coeff[i] = poly_coeff[i] + coefficients[i];
        if (i < other.numberOfTerms)
            poly_coeff[i] = poly_coeff[i] - other.coefficients[i];
    }

    /*for (int i = 0; i < maxOfTerms; i++)
    {
        cout << "poly_coeff[i] " << poly_coeff[i] << endl;
    }*/

    Polynomial poly(poly_coeff, maxOfTerms);

    return poly;
}

// оператор множення
Polynomial Polynomial::operator*(const Polynomial& other) const
{
    int maxOfTerms, degree, s = 0;
    if (other.numberOfTerms > numberOfTerms)
        maxOfTerms = other.numberOfTerms;
    else
        maxOfTerms = numberOfTerms;

    degree = (numberOfTerms - 1) + (other.numberOfTerms - 1);

    Complex* poly_coeff = new Complex[maxOfTerms];
    Complex zero(0, 0);

    for (int i = 0; i < degree; i++)
        for (int j = 0; i < degree; j++)
        {
            poly_coeff[s] = zero;
            poly_coeff[s] = coefficients[i] * other.coefficients[j];
            s++;
        }

    /*for (int i = 0; i < maxOfTerms; i++)
    {
        cout << "poly_coeff[i] " << poly_coeff[i] << endl;
    }*/

    Polynomial poly(poly_coeff, degree);

    return poly;
}

Polynomial& Polynomial::operator+=(const Polynomial& r)
{
    *this = *this + r;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& r)
{
    *this = *this - r;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& r)
{
    *this = *this * r;
    return *this;
}

// похідна поліному
Polynomial Polynomial::derivative()
{
    Complex * poly_coeff = new Complex[numberOfTerms - 1];

    for (int i = 0; i < numberOfTerms - 1; i++)
    {
        double re = coefficients[i + 1].real() * (i + 1);
        double im = coefficients[i + 1].imag() * (i + 1);
        Complex c(re, im);

        poly_coeff[i] = c;
    }

    /*for (int i = 0; i < numberOfTerms - 1; i++)
    {
        cout << "poly_coeff[i] " << poly_coeff[i] << endl;
    }*/

    Polynomial der(poly_coeff, numberOfTerms - 1);

    return der;
}

// значення поліному в точці х
Complex Polynomial::value(Complex x)
{
    Complex c;

    for (int i = 0; i < numberOfTerms; i++)
    {
        c = c + (coefficients[i] * (x^i));
    }

    return c;
}

ostream& operator<<(ostream& out, const Polynomial& cp) {
    cp.printPolynomial(out);
    return out;
}

Polynomial::~Polynomial()
{
    delete[] coefficients;
}
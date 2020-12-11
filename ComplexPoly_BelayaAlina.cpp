#include <iostream>
#include "ComplexPoly_BelayaAlina.h"
using namespace std;

// конструктор комплексного числа
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
void Complex::print() const
{
	cout << re << "+" << im << "i" << endl;
}

// додавання комплексних чисел
Complex Complex::operator+(Complex c2)
{
	Complex res(re + c2.real(), im + c2.imag());
	return res;
}

// множення комплексних чисел
Complex Complex::operator*(Complex c2)
{
	double r = re * c2.real() - im * c2.imag();
	double i = re * c2.imag() + im * c2.real();
	Complex res(r, i);
	return res;
}

// піднесення комплексного числа до степеня
Complex Complex::operator^(int power)
{
	if (power == 0)
		return Complex(1, 0);

	Complex res = *this;
	for (int i = 1; i < power; ++i)
		res = res * (*this);
	return res;
}

//створення порожнього массиву коефіцієнтів та степенів х для подальшого заповнення
Polynomial::Polynomial()
{
    for (int t = 0; t < maxTerms; ++t)
    {
        arr[t] = 0;
        coefficients[t] = 0;
        exponents[t] = 0;
    } 
    numberOfTerms = 0;
}

// вивід поліному
void Polynomial::printPolynomial() const
{
    int count; // лічильник доданків для виводу полінома
    bool exist = false; // перевірка, чи існують доданки у поліномі

    // вивід доданку з степенню х == 0
    if (coefficients[0]) 
    {
        cout << coefficients[0];
        count = 1; // у поліномі лише один доданок з степенню х == 0
        exist = true; // хоча б один доданок існує
    }
    else
    {
        if (coefficients[1])
        {
            cout << coefficients[1] << 'x';  // вивід першого доданка без знаку
            if ((exponents[1] != 0) && (exponents[1] != 1))
                cout << '^' << exponents[1];

            exist = true; // хоча б один доданок існує
        }
        count = 2; // у поліномі лише один доданок у вигляді числа
    }

    // вивід залишившихся доданків з їхніми знаками
    for (int x = count; x < maxTerms; ++x) 
    {
        if (coefficients[x] != 0)
        {
            cout << showpos << coefficients[x] << noshowpos << 'x';

            if ((exponents[x] != 0) && (exponents[x] != 1))
                cout << '^' << exponents[x];

            exist = true; // хоча б один доданок існує
        }
    }

    // якщо у поліномі немає жодного доданку, то вивести нуль
    if (!exist) 
        cout << '0';

    cout << endl;
}

// оператор присвоєння 
Polynomial& Polynomial::operator=(const Polynomial& other) 
{
    exponents[0] = other.exponents[0]; // присвоєння доданку з степенню х == 0
    coefficients[0] = other.coefficients[0];

    for (int s = 1; s < maxTerms; ++s)
    {
        // якщо степінь х не дорівнює 0, то переприсвоїти доданок
        if (other.exponents[s] != 0) 
        {
            exponents[s] = other.exponents[s];
            coefficients[s] = other.coefficients[s];
        }
        else
        {
            if (exponents[s] == 0)
                break;

            exponents[s] = 0;
            coefficients[s] = 0;
        }
    }

    return *this;
}

// оператор додавання
Polynomial Polynomial::operator+(const Polynomial& other) const 
{
    Polynomial poly; // новій поліном
    int s;

    poly.coefficients[0] = coefficients[0] + other.coefficients[0]; // додавання доданків з степенню х == 0

    for (s = 1; (s < maxTerms) && (other.exponents[s] != 0); ++s)
    {
        // присвоєння новому поліному коефіцієнти та степені того поліному, який справа від знаку +
        //окрім тих, що мають степінь х == 0
        poly.coefficients[s] = other.coefficients[s];
        poly.exponents[s] = other.exponents[s];
    }

    for (int x = 1; x < maxTerms; ++x)
    {
        bool exist = false; // перевірка, чи існує такий степінь х у поліномі

        for (int t = 1; (t < maxTerms) && (!exist); ++t)
            if (exponents[x] == poly.exponents[t])
            {
                // якщо у поліномів є однакові степені, то їх коефіцієнти додаються
                poly.coefficients[t] += coefficients[x];
                exist = true;  // однакові степені існують
            }
        
        // якщо у поліномі не знайдено однакових степенів,
        //то до нового поліному додаються доданки іншого
        if (!exist)
        {
            poly.exponents[s] = exponents[x];
            poly.coefficients[s] += coefficients[x];
            ++s;
        }
    }

    return poly;
}

// оператор віднімання
Polynomial Polynomial::operator-(const Polynomial& other) const
{
    Polynomial poly; // новій поліном
    int s;

    poly.coefficients[0] = coefficients[0] - other.coefficients[0]; // віднімання доданків з степенню х == 0

    for (s = 1; (s < maxTerms) && (exponents[s] != 0); ++s)
    {
        // присвоєння новому поліному коефіцієнти та степені того поліному, який зліва від знаку -
        //окрім тих, що мають степінь х == 0
        poly.coefficients[s] = coefficients[s];
        poly.exponents[s] = exponents[s];
    }

    for (int x = 1; x < maxTerms; ++x)
    {
        bool exist = false; // перевірка, чи існує такий степінь х у поліномі

        for (int t = 1; (t < maxTerms) && (!exist); ++t)

            if (other.exponents[x] == poly.exponents[t])
            {
                // якщо у поліномів є однакові степені, то їх коефіцієнти віднімаються
                poly.coefficients[t] -= other.coefficients[x];
                exist = true;  // однакові степені існують
            }

        // якщо у поліномі не знайдено однакових степенів,
        //то від нового поліному віднімаються доданки іншого
        if (!exist)
        {
            poly.exponents[s] = other.exponents[x];
            poly.coefficients[s] -= other.coefficients[x];
            ++s;
        }
    }

    return poly;
}

// оператор множення
Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polynomial poly;
    int s = 1;

    for (int x = 0; (x < maxTerms) && (x == 0 || coefficients[x] != 0); ++x)
        for (int y = 0; (y < maxTerms) && (y == 0 || other.coefficients[y] != 0); ++y)
            if (coefficients[x] * other.coefficients[y])
                if ((exponents[x] == 0) && (other.exponents[y] == 0))
                {
                    // якщо степені х == 0, перемножаємо його коефіцієнти
                    poly.coefficients[0] += coefficients[x] * other.coefficients[y];
                }
                else
                {
                    // у іншому випадку додаємо до порожнього поліному перемножені коефіцієнти, та додані степені
                    poly.coefficients[s] = coefficients[x] * other.coefficients[y];
                    poly.exponents[s] = exponents[x] + other.exponents[y];
                    ++s;
                }

    similarTerms(poly); // зведення подібних доданків 

    return poly;
}

// оператор ділення
/*працює лише якщо у дільнику при найстаршому степені стоїть коефіцієнт 1*/
Polynomial Polynomial::operator/(const Polynomial& other) const
{
    Polynomial poly, first, p1, p2, p3;
    int max1, max2;

    // збереження значень діленого
    for (int i = 0; i <= numberOfTerms; ++i)
    {
        first.coefficients[i] = coefficients[i];
        first.exponents[i] = exponents[i];
    }

    // пошук старшого степеню в діленому
    max1 = exponents[0];
    for (int i = 1; i <= numberOfTerms; ++i)
        if (max1 < exponents[i])
        {
            max1 = exponents[i];
        }

    // пошук старшого степеню в дільнику
    max2 = other.exponents[0];
    for (int i = 1; i <= other.numberOfTerms; ++i)
        if (max2 < other.exponents[i])
        {
            max2 = other.exponents[i];
        }

    do
    {
        // р1 - порожній поліном, який буде містити частини частки
        p1.exponents[1] = max1 - max2; // степінь доданку, на який потрібно помножити ділене

        for (int i = 0; i <= maxTerms; ++i)
            if (first.exponents[i] == max1) // пошук коефіцієнта при старшому степені
                                            // та його присвоєння в р1
            {
                if (p1.exponents[1] != 0)
                    p1.coefficients[1] = first.coefficients[i];
                else
                    p1.coefficients[0] = first.coefficients[i];
            }

        poly += p1; // poly - порожній поліном, який буде містити частку

        p2 = first - other * p1; // метод ділення поліномів в стовпчик

        first = p2;

        max1 -= 1;
        p1 = p3;

    } while (max1 >= max2);

    return poly;
}

// оператор ділення з остачею
Polynomial Polynomial::operator%(const Polynomial& other) const
{
    Polynomial poly, first, p1, p2, p3;
    int max1, max2;

    for (int i = 0; i <= numberOfTerms; ++i)
    {
        first.coefficients[i] = coefficients[i];
        first.exponents[i] = exponents[i];
    }

    max1 = exponents[0];
    for (int i = 1; i <= numberOfTerms; ++i)
        if (max1 < exponents[i])
        {
            max1 = exponents[i];
        }

    max2 = other.exponents[0];
    for (int i = 1; i <= other.numberOfTerms; ++i)
        if (max2 < other.exponents[i])
        {
            max2 = other.exponents[i];
        }

    do
    {
        p1.exponents[1] = max1 - max2;

        for (int i = 0; i <= maxTerms; ++i)
            if (first.exponents[i] == max1)
            {
                if (p1.exponents[1] != 0)
                    p1.coefficients[1] = first.coefficients[i];
                else
                    p1.coefficients[0] = first.coefficients[i];
            }

        poly += p1;

        p2 = first - other * p1;

        first = p2;

        max1 -= 1;
        p1 = p3;

    } while (max1 >= max2);

    return p2;
}

// зведення подібних доданків 
void Polynomial::similarTerms(Polynomial& p)
{
    Polynomial poly = p;

    // "видаляемо" елементи поліному
    for (int x = 0; x < maxTerms; ++x)
    {
        p.coefficients[x] = 0;
        p.exponents[x] = 0;
    }

    for (int x = 1; x < maxTerms; ++x)
    {
        for (int y = x + 1; y < maxTerms; ++y)
            if (poly.exponents[x] == poly.exponents[y])
            {
                // шукаємо однакові степені та додаємо їх коефіцієнти
                poly.coefficients[x] += poly.coefficients[y];
                poly.exponents[y] = 0;
                poly.coefficients[y] = 0;
            }
    }

    p = poly;
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

Polynomial& Polynomial::operator/=(const Polynomial& r)
{
    *this = *this / r;
    return *this;
}

void Polynomial::enterTerms()
{
    bool exist = false;
    double c;
    int e, term;

    cout << "\nEnter number of polynomial terms: ";
    cin >> numberOfTerms; // введення кількості доданків

    for (int n = 0; n < maxTerms && n < numberOfTerms; ++n)
    {
        cout << "\nEnter coefficient: ";
        cin >> c; // введення коєффіцієнта при х

        cout << "Enter exponent: ";
        cin >> e; // введення степеня х

        if (c != 0)
        {
            // переміщення доданку з степенню х == 0 на перше місце
            if (e == 0)
            {
                coefficients[0] += c;
                continue;
            }

            // заповнення масиву коефіцієнтів та степенів
            for (term = 1; (term < maxTerms) && (coefficients[term] != 0); ++term)
                if (e == exponents[term])
                {
                    coefficients[term] += c;
                    exponents[term] = e;
                    exist = true;  // хоча б один доданок існує
                }

            if (!exist)
            {
                coefficients[term] += c;
                exponents[term] = e;
            }
        }
    }
}

// значення поліному в точці х
void Polynomial::value(double x) const
{
    double result = 0, power = 1;

    for (int i = 0; i <= numberOfTerms; ++i)
    {
        result += coefficients[i] * power;
        power *= x;
    }

    cout << result << endl;
}

// похідна поліному
Polynomial& Polynomial::derivative() const
{
    Polynomial poly;

    for (int i = 0; i <= numberOfTerms; ++i)
    {
        if ((exponents[i] != 0) && (exponents[i] - 1) != 0)
        {
            // якщо степінь не дорівнює 0 та 1, понижаемо степінь
            poly.coefficients[i] += exponents[i] * coefficients[i];
            poly.exponents[i] += exponents[i] - 1;
        }
        else if (exponents[i] == 0)
        {
            // якщо степінь дорівнює 0, "видаляємо" його коефіцієнти
            poly.coefficients[i] = 0;
            poly.exponents[i] = 0;
        }
        else if ((exponents[i] - 1) == 0)
        {
            // якщо степінь == 1, переміщаємо змінений коефіцієнт на початок
            poly.coefficients[0] += exponents[i] * coefficients[i];
            poly.exponents[0] = 0;
        }
    }

    return poly;
}

// повернення кількості доданків
int Polynomial::getNumberOfTerms() const
{
    return numberOfTerms;
}

// повернення степеня по його порядку в массиві
int Polynomial::getTermExponent(int term) const
{
    return exponents[term];
}

// повернення коефіцієнта по його порядку в массиві
double Polynomial::getTermCoefficient(int term) const
{
    return coefficients[term];
}

// переприсвоєння коефіцієнта по його порядку
void Polynomial::setCoefficient(int term, double coefficient)
{
    if (coefficients[term] == 0) // якщо немає такого коефіцієнта, то вивести помилку
        cout << "No term at this location, cannot set term." << endl;
    else // у іншому випадку присвоїти значення
        coefficients[term] = coefficient;
}

Polynomial::~Polynomial()
{
    // порожній деструктор
}


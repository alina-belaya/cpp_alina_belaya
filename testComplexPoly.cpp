#include <iostream> 
#include <fstream>
#include "ComplexPoly_BelayaAlina.h"
using namespace std;

template <class Container>
void split(const string& str, Container& container)
{
    stringstream ss(str);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;

    vector<string> vstrings(begin, end);
    copy(vstrings.begin(), vstrings.end(), back_inserter(container));
}

Complex* get_coefficients(vector<string> vect, int size)
{
    Complex* result = new Complex[size];
    int s = 0;

    for (int i = 0; i < size; i += 2)
    {
        double re = stof(vect[i]);
        double im = stof(vect[i + 1]);
        Complex c(re, im);
        result[s++] = c;
    }

    return result;
}

void start(string a_string, string b_string, string x_string)
{
    int out, size_a, size_b, size_x;

    vector<string> a_vector;
    split(a_string, a_vector);
    Complex* a_coeff = get_coefficients(a_vector, a_vector.size());
    size_a = a_vector.size() / 2;
    Polynomial a(a_coeff, size_a);

    vector<string> b_vector;
    split(b_string, b_vector);
    Complex* b_coeff = get_coefficients(b_vector, b_vector.size());
    size_b = b_vector.size() / 2;
    Polynomial b(b_coeff, size_b);

    vector<string> x_vector;
    split(x_string, x_vector);
    Complex* x_value = get_coefficients(x_vector, x_vector.size());
    size_x = x_vector.size() / 2;
    Complex x = x_value[0];

    cout << "\nHow do you want to output polynomial?\nPut 0 to output through console or 1 - through file: ";
    cin >> out;

    if (out == 0)
    {
        ofstream output("output.txt");

        cout << "\nPolynomial A\n";
        cout << a << endl;

        cout << "\nPolynomial B\n";
        cout << b << endl;

        cout << "\nValue in x\n";
        cout << a.value(x) << endl;

        cout << "\nA + B\n";
        Polynomial add = a + b;
        cout << add << endl;

        cout << "\nA - B\n";
        Polynomial divis = a - b;
        cout << divis << endl;

        cout << "\nA * B\n";
        Polynomial multi = a * b;
        cout << multi << endl;

        cout << "\nTest polynomial deviation\n";
        cout << a.derivative() << endl;
    }
    else if (out == 1)
    {
        ofstream output("output.txt");

        output << "\nPolynomial A\n";
        output << a << endl;

        output << "\nPolynomial B\n";
        output << b << endl;

        output << "\nValue in x\n";
        output << a.value(x) << endl;

        output << "\nA + B\n";
        output << a + b << endl;

        output << "\nA - B\n";
        output << a - b << endl;

        output << "\nA * B\n";
        output << a * b << endl;

        output << "\nDerivative\n";
        output << a.derivative() << endl;
    }
    else
    {
        cout << "Wrong choice" << endl;
    }
}

void console()
{
    cout << "\nInput polynomial coefficients (real and imaginary) through space\n";

    string a, b, x;
    cin.ignore();

    cout << "\nPolynomial A: ";
    getline(cin, a);

    cout << "\nPolynomial B: ";
    getline(cin, b);

    cout << "\nX: ";
    getline(cin, x);

    start(a, b, x);
}

void file()
{
    ifstream file("input.txt");
    string a, b, x;

    getline(file, a);
    getline(file, b);
    getline(file, x);

    file.close();
    start(a, b, x);
}

void run_project()
{
	int running;
    cout << "How do you want to input polynomial?\nPut 0 to input through console or 1 - through file: ";
	cin >> running;

    if (running == 0)
        console();
    else if (running == 1)
        file();
    else
        cout << "Wrong choice" << endl;

}

int main()
{
    run_project();
    return 0;
}
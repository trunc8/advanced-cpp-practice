#include <iostream>
using namespace std;

class Complex {
private:
    double real, imaginary;
public:
    Complex ();
    Complex (double real, double imaginary);
    Complex (const Complex &c2);

    double getReal() const {
        return real;
    }
    double getImaginary() const {
        return imaginary;
    }

    const Complex &operator=(const Complex &c2);
    double operator[](const Complex &c2);
    // Complex &operator+(const Complex &c2) const;
    // bool operator==(const Complex &c2) const;

    // friend ostream &operator<<(ostream &out, const Complex &complex);
};

Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

bool operator==(const Complex &c1, const Complex &c2);
bool operator!=(const Complex &c1, const Complex &c2);

ostream &operator<<(ostream &out, const Complex &complex);


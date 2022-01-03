#include "Complex.h"

Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
}

Complex operator+(const Complex &c1, double d) {
    return Complex(c1.getReal()+d, c1.getImaginary());
}

Complex operator+(double d, const Complex &c1) {
    return Complex(c1.getReal()+d, c1.getImaginary());
}

bool operator==(const Complex &c1, const Complex &c2) {
    return (c1.getReal()==c2.getReal() && c1.getImaginary()==c2.getImaginary());
}

bool operator!=(const Complex &c1, const Complex &c2){
    return !(c1==c2);
}

Complex::Complex() : real(0), imaginary(0) {}

Complex::Complex (double real, double imaginary) :
    real(real), imaginary(imaginary) {}

Complex::Complex (const Complex &c2) {
    real = c2.getReal();
    imaginary = c2.getImaginary();
}

const Complex &Complex::operator=(const Complex &c2) {
    real = c2.getReal();
    imaginary = c2.getImaginary();
    return *this;
}

double Complex::operator[](const Complex &c2) {
    return (real-c2.getReal());
}

// Complex &Complex::operator+(const Complex &c2) const {
//     Complex *sum = new Complex(real+c2.getReal(), imaginary+c2.getImaginary());
//     return *sum;
// }

// bool Complex::operator==(const Complex &c2) const {
//     return (real==c2.getReal() && imaginary==c2.getImaginary());
// }

ostream &operator<<(ostream &out, const Complex &complex) {
    out << "(" << complex.getReal() << "," << complex.getImaginary() << ")";
    return out;
}

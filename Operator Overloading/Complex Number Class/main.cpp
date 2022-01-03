#include "Complex.h"

int main() {
    Complex c1(10,-9.1);
    cout << c1 << endl;

    Complex c2 = c1; //copy constructor
    cout << c2 << endl;

    Complex c3;
    c3 = c1+c2; //assignment operator
    cout << c3 << endl;

    cout << 1+c1+c2+1+c3+1 << endl;

    if (c1==c3)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;
    if (c1!=c2)
        cout << "Not Equal" << endl;
    else
        cout << "Equal" << endl;

    double distance = c1[Complex(0,0)];
    cout << "Distance:" << distance << endl;
    return 0;
}

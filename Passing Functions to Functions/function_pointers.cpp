#include <iostream>
using namespace std;

void test() {
    cout << "Hello" << endl;
}

double sum(double a, double b) {
    return a+b;
}

int main() {
    void (*pTest)() = test;
    pTest();

    double (*pSum)(double, double) = sum;
    cout << pSum(1.5,3.51) << endl;

    cout << typeid(test).name() << endl;
    cout << typeid(*pTest).name() << endl;
    cout << typeid(&sum).name() << endl;

    
    return 0;
}

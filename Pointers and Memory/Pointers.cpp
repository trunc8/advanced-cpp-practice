#include <iostream>
using namespace std;

void manipulate (double *pvalue) {
    cout << "2. Before manipulate: " << *pvalue << endl;
    *pvalue = 22.7;
    cout << "3. After manipulate: " << *pvalue << endl;
}

int main() {
    int nValue = 8;
    int *pValue = &nValue;
    cout << "nValue: " << nValue << endl;
    cout << sizeof(long) << endl;
    cout << "pValue address: " << pValue+1 << endl;
    cout << "pValue value using [0]: " << pValue[0] << endl;
    cout << "pValue value using *: " << *pValue << endl;
    cout << endl;

    double dValue = 10.5;
    cout << "1. Double value: " << dValue << endl;
    manipulate(&dValue);
    cout << "4. Double value: " << dValue << endl;

    return 0;
}

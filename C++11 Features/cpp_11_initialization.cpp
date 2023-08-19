#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nValue {5};
    cout << nValue << endl;

    string name {"Bibb"};
    cout << name << endl;

    // int* pInts {new int[4] {1,2,3,4} }; // looks ugly
    int* pInts = new int[4] {1,2,3,4};
    cout << pInts[2] << endl;
    
    struct {
        string name;
        int id;
    } s1 {"Hello", 7};
    cout << s1.name << endl;

    vector<string> names {"bi", "ti", "ki", "si"};
    cout << names[3] << endl;

    return 0;
}

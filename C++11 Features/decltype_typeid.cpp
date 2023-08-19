#include <iostream>
#include <typeinfo>
using namespace std;

const int foo() {
    cout << "foo" << endl;
    return 9;
}

int main() {
    string value;
    cout << typeid(value).name() << endl;

    decltype(value) name = "Ebba";
    cout << typeid(name).name() << endl;
    cout << name << endl;

    cout << typeid(foo).name() << endl;
    
    return 0;
}

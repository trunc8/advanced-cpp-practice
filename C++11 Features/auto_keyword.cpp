#include <iostream>
using namespace std;

template<typename T, typename S>
auto test1(T value1, S value2)-> decltype(value1+value2) {
    return value1+value2*1.11;
}

int getNumber() {
    return 999;
}

auto test2() -> decltype(getNumber()) {
    return getNumber();
}

int main() {
    auto nValue = 99.f;
    cout << nValue << endl;
    cout << typeid(nValue).name() << endl;

    auto stringValue = "Hello";
    cout << stringValue << endl;

    cout << test1(5, 10) << endl;
    
    cout << test2() << endl;
    return 0;
}

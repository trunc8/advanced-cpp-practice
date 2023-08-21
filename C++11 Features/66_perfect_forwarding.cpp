#include<iostream>
using namespace std;

class Test {
};

void check(Test&) {
    cout << "lvalue" << endl;
}

void check(Test&&) {
    cout << "rvalue" << endl;
}

template<typename T>
void run(T &&val) {
    // This converts to lvalue irrespective of the type of val
    // check(val);

    // Solution: PERFECT FORWARDING
    check(static_cast<T>(val));
    // reinterpret_cast and dynamic_cast don't work
    // check(dynamic_cast<T>(val));
    // check(reinterpret_cast<T>(val));
    check(forward<T>(val));
    
}

int main()
{
    Test test;
    check(test);
    run(test);
    cout << endl;

    check(Test());
    run(Test());
    cout << endl;
    return 0;
}
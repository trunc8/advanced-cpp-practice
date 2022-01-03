#include <iostream>
using namespace std;

template<typename T>
void show() {
    T num = 65.5;
    cout << num << endl;
}

int main() {
    show<char>();
    show<int>();
    show<double>();
    return 0;
}

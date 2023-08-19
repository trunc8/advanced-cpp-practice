#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class ring {
public:
    class iterator;
};


template<typename T>
class ring<T>::iterator {
public:
    void print() {
        cout << "Inside iterator class: " << T() << endl;
    }
};

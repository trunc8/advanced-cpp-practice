#include <iostream>
using namespace std;

class Parent {
public:
    int one;
public:
    Parent(): one(0) {
    }

    Parent(const Parent &other) {
        one = other.one;
        cout << "copy parent" << endl;
    }
    virtual void print() {
        cout << "parent" << endl;
    }
};

class Child: public Parent {
public:
    int two;
public:
    Child() : two(2) {}
    void print() {
        cout << "child" << endl;
    }
};

int main() {

    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child(); // object slicing
    p2.print();
    
    return 0;
}

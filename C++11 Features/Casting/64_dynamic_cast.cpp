#include<iostream>
using namespace std;

class Parent {
public:
    virtual void speak() {
        cout << "Parent!" << endl;
    }
};

class Brother: public Parent {
public:
    void brotherSpeak() {
        cout << "Brother!" << endl;
    }

};

int main()
{
    float value = 3.32;

    cout << (int)value << endl; // Comes from C
    cout << int(value) << endl;
    cout << static_cast<int>(value) << endl;

    Parent parent;
    Brother brother;

    Parent *ppb = &brother;
    Brother *pbb = dynamic_cast<Brother *>(&parent); // Doesn't work if parent function
    // not virtual. Complains that Parent class in not polymorphic.

    if (pbb == nullptr) {
        cout << "Invalid pointer" << endl;
    } else {
        cout << pbb << endl;
    }
    
    return 0;
}
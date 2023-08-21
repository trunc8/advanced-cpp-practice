#include<iostream>
using namespace std;

class Parent {
public:
    void speak() {
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
    // Brother *pbb = &parent; // Gives error invalid conversion from ‘Parent*’ to ‘Brother*
    Brother *pbb = static_cast<Brother *>(&parent);
    cout << pbb << endl;

    ppb->speak();
    pbb->speak();
    pbb->brotherSpeak();

    Parent &&p = static_cast<Parent &&>(parent);
    p.speak();
    
    return 0;
}
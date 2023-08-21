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

class Sister: public Parent {

};

int main()
{
    Parent parent;
    Brother brother;
    Sister sister;

    Parent *ppb = &brother;
    Sister *psb = dynamic_cast<Sister *>(&parent);
    if (psb == nullptr) {
        cout << "Invalid pointer" << endl;
    } else {
        cout << psb << endl;
    }

    // Does less checking than dynamic cast
    Sister *psb2 = static_cast<Sister *>(&parent);
    if (psb2 == nullptr) {
        cout << "Invalid pointer" << endl;
    } else {
        cout << psb2 << endl;
    }

    // Almost always avoid
    Sister *psb3 = reinterpret_cast<Sister *>(&parent);
    if (psb3 == nullptr) {
        cout << "Invalid pointer" << endl;
    } else {
        cout << psb3 << endl;
    }
    
    return 0;
}
#include <iostream>
using namespace std;

class Test {
private:
    string name;
    int id;
public:
    Test() : id(0), name(""){
    }
    Test(int id, string name) :
        id(id), name(name) {
    }
    void print() {
        cout << id << ": " << name << endl;
    }
    const Test &operator=(const Test &other) {
        cout << "Using assignment operator" << endl;
        id = other.id+1;
        name = other.name;

        // return Test(); // leads to segmentation fault

        return *this;
    }
    Test(const Test &other) {
        cout << "Using copy constructor" << endl;
        id = other.id+2;
        name = other.name;
    }
};

int main() {

    Test t1(10, "Micky");
    cout << "Printing t1, ";
    t1.print();
    cout << endl;

    Test t2;
    cout << "Printing empty t2, ";
    t2.print();
    cout << endl;
    t2 = t1;
    cout << "Printing assigned t2, ";
    t2.print();
    cout << endl;

    Test t3 = t1;
    cout << "Printing copy constructor t3, ";
    t3.print();
    cout << endl;


    Test t4(t1);
    cout << "Printing copy constructor t4, ";
    t4.print();
    cout << endl;

    Test t5, t6;
    t6 = t5 = t1;
    cout << "Printing assigned t5 and t6, " << endl;
    t5.print();
    t6.print();

    return 0;
}

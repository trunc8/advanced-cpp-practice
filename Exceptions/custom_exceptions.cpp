#include <iostream>
#include <exception>
using namespace std;

class MyException: public exception {
public:
    virtual const char* what() const throw() {
        return ("Something bad happened");
    }
};

void badFunction () {
    throw MyException();
}

int main() {
    try {
        badFunction();
    }
    catch (MyException e) {
        cout << "Caught custom exception: " << e.what() << endl;
    }

    cout << "Still running" << endl;

    return 0;
}

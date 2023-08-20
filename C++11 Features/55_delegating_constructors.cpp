#include<iostream>
using namespace std;

class Parent {
    int dogs {5};
    string text {"hello"};
public:
    /***
     * In C++98 we couldn't call one constructor from another
     * We have to define an init method that different constructors had to call.
     * In C++11, one constructor can call another constructor.
     */

    Parent(): Parent("hello") {
        cout << "No-parameter parent constructor" << endl;
    }
    Parent(string text) {
        this->text = text;
        cout << "Parameterized parent constructor: " << this->text << endl;
    }
};

class Child: public Parent {
public:
    Child() = default; // This line can be removed.
};

int main()
{
    Parent parent("amnesty");
    Child child; // Gives error if Parent() default constructor is commented out
    return 0;
}
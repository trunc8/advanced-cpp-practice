#include<iostream>
using namespace std;

class Test{};

Test getTest(){
    return Test();
}

void check(Test&){
    cout << "lvalue function!" << endl;
}

/***
 * If I make above function check(const Test&), rvalue will still prefer
 * below function.
 * If I also comment below function out, rvalue will be forced to use above
 * function, but it won't complain.
*/
void check(Test&&){
    cout << "rvalue function!" << endl;
}

void checkInt(int&){ cout << "lvalue checkInt" << endl;}
void checkInt(int&&){ cout << "rvalue checkInt" << endl;}

int main()
{
    Test test1 = getTest();
    
    Test &lTest1 = test1; // lvalue reference
    Test &&rTest1 = Test(); // rvalue reference

    check(test1); // lvalue
    check(Test()); // rvalue
    check(getTest()); // rvalue

    int val = 1;
    checkInt(val); // lvalue
    checkInt(++val); // lvalue
    checkInt(val++); // rvalue

    return 0;
}
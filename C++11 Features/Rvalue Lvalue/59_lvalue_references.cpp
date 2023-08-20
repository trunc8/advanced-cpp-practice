#include<iostream>
using namespace std;

class Test{};

Test getTest(){
    return Test();
}

int main()
{
    Test test1 = getTest();
    // Binding lvalue reference to lvalue-
    Test &rTest1 = test1;

    /***
     * Error: cannot bind non-const lvalue reference of type ‘Test&’
     * to an rvalue of type ‘Test’
     */
    // Test &rTest2 = getTest();

    // Now binding const lvalue reference to rvalue-
    const Test &rTest3 = getTest(); // works
    const int &rvalue = 7; // Also works!

    /***
     * Test() rvalue works below
     * Copy constructor has const lvalue reference
     */
    Test test2{Test()};

    return 0;
}
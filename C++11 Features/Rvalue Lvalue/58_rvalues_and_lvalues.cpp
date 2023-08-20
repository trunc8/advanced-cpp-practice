#include<iostream>
using namespace std;

class Test{};

Test getTest(){
    return Test();
}

int main()
{
    /***
     * In C++98, lvalue meant left to the = sign and rvalue mean to be right
     * value1: lvalue
     * 7: rvalue
    */
    int value1 = 7;
    /***
     * In C++11, lvalue is anything whose address can be assigned
     * value1: lvalue, because we can take its address
    */
    int *pValue1 = &value1;

    Test test1;
    Test *pTest1 = &test1;
    // Test *pTest2 = &getTest(); // Error: Taking address of rvalue
    int *pValue3 = &++value1;
    cout << value1 << "\t" << *pValue3 << endl;

    // int *pValue4 = &value1++; // Error: lvalue required as unary ‘&’ operand
    // Even putting parenthesis doesn't work like &(value1++)
    // cout << value1 << "\t" << *pValue << endl;

    // int s = &(7 + value1); // Error: It becomes an rvalue

    // int t = &(value1*value1); // Error: Also becomes an rvalue

    return 0;
}
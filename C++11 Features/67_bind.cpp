#include <iostream>
#include <functional>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c)
{
    cout << endl
         << a << ", " << b << ", " << c << endl;
    return (a + b + c);
}

class Test
{
public:
    int memberAdd(int a, int b, int c)
    {
        cout << endl
             << a << ", " << b << ", " << c << endl;
        return (a + b + c);
    }

    static int staticMemberAdd(int a, int b, int c)
    {
        cout << endl
             << a << ", " << b << ", " << c << endl;
        return (a + b + c);
    }
};

int run(function<int(int, int)> func)
{
    return func(5, 5);
}

int main()
{
    cout << add(10, 20, 30) << endl;

    // Function pointers don't need &, member function pointers do.
    auto calculate1 = bind(add, 10, 20, 30);
    cout << calculate1() << endl;

    function<int(int, int, int)> calculate2 = bind(add, _1, _2, _3);
    cout << calculate2(1, 2, 3) << endl;

    // hardcoded arguments and mixing up placeholders
    auto calculate3 = bind(add, 100, _2, _1);
    cout << calculate3(10, 20) << endl;

    cout << run(calculate3) << endl;
    
    /***
     * A pointer to member is only formed when an explicit & is used 
     * and its operand is a qualiﬁed-id not enclosed in parentheses.
    */
    auto calculate4 = bind(&Test::memberAdd, Test(), _1, 10, _2);
    cout << run(calculate4) << endl;

    // Works both with and without &, just like any regular function pointer
    auto calculate5 = bind(Test::staticMemberAdd, _1, -10, _2);
    cout << run(calculate5) << endl;

    return 0;
}
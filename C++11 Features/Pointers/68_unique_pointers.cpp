#include <iostream>
#include <memory>
using namespace std;

class Test
{
public:
    Test()
    {
        std::cout << "created" << endl;
    }
    void greet()
    {
        std::cout << "hello" << endl;
    }
    ~Test()
    {
        std::cout << "destroyed" << endl;
    }
};

class Temp
{
private:
    unique_ptr<Test> pTest{new Test()};

public:
    Temp() {}
    Temp(const Temp &) {}
};

int main()
{
    {
        unique_ptr<Temp> pTemp;
        Temp temp;
        // pTemp = static_cast<unique_ptr<Temp> >(&temp); // Failed
        pTemp = make_unique<Temp>(temp); // Needs the copy constructor
        cout << endl;

        pTemp = nullptr; // Destroys some Test object
        cout << endl;

        pTemp = make_unique<Temp>(Temp());
    }
    cout << endl;

    unique_ptr<int> pVal(new int(5));
    *pVal = 10;
    std::cout << *pVal << endl;

    std::cout << endl;
    Test *ptr = new Test();
    ptr[0].greet(); // Works. [0] works with bare pointers
    delete ptr;

    std::cout << endl;
    {
        unique_ptr<Test> pTest(new Test());
        (*pTest).greet();
        pTest->greet();
        // pTest[0].greet(); // Error. [0] Doesn't work with unique_ptr
    }
    std::cout << endl;

    unique_ptr<Test[]> pTestArr(new Test[2]);
    pTestArr[1].greet();

    std::cout << "Finished" << endl;
    return 0;
}
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

int main()
{
    shared_ptr<Test> pTest2(nullptr);

    {
        shared_ptr<Test> pTest = make_shared<Test>();
        pTest2 = pTest;
    }
    cout << "Finished" << endl;
    return 0;
}
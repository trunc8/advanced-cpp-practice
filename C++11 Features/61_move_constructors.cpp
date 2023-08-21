#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

class Test{
private:
    static const int SIZE{10};
    int *_pBuffer{nullptr};
public:
    Test() {
        cout << "Default initialization" << endl;
        _pBuffer = new int[SIZE] { };
    }

    /***
     * RULE OF 3:
     *  Copy constructor
     *  Assignment operator
     *  Destructor
    */
    Test(const Test &other) {
        cout << "Copy initialization" << endl;
        _pBuffer = new int[SIZE] { };
        memcpy(this->_pBuffer, other._pBuffer, SIZE*sizeof(int));
    }
    Test &operator=(const Test &other) {
        cout << "Assignment initialization" << endl;
        _pBuffer = new int[SIZE] { };
        memcpy(_pBuffer, other._pBuffer, SIZE*sizeof(int));
        return *this;
    }
    ~Test() {
        cout << "Destructor" << endl;
        delete [] _pBuffer;
    }

    // THE NEW MOVE CONSTRUCTOR!
    Test(Test &&other) {
        cout << "Move constructor" << endl;
        _pBuffer = other._pBuffer;
        other._pBuffer = nullptr;
    }
};

Test getTest(){
    return Test();
}

int main()
{
    vector<Test> vec;
    vec.push_back(Test());

    cout << endl;
    
    /***
     * If I don't implement assignment operator, below code complains-
     * error: use of deleted function ‘constexpr Test& Test::operator=(const Test&)
    */
    Test test1;
    test1 = getTest();



    return 0;
}
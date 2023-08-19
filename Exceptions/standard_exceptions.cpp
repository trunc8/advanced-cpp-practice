#include <iostream>
using namespace std;

class MemoryFullClass {
public:
    MemoryFullClass() {
        char *pMemory = new char[1000000000000];
        delete[] pMemory;
    }
};

int main() {
    try {
        MemoryFullClass mem;
    }
    catch (bad_alloc &e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    cout << "Still running" << endl;

    return 0;
}

#include <iostream>
using namespace std;

class risc { // singleton
    protected:
        // static unsigned long registers[8];

    public:
        static int i;
        static unsigned long registers[8];
        unsigned long operator [](int i) const
        {
            return registers[i];
        }
        unsigned long &operator[](int i) {
            return registers[i];
        }
};

int i=1;
unsigned long risc::registers[] = {0,0,0,0,0,0,0};

int main() {
    risc r;
    cout << risc::registers[7] << endl;
    for (int i=0; i<8; i++) {
        r[i] = i;
    }
    cout << risc::registers[7] << endl;
    for (int i=7; i>=0; i--)
        cout << " " << r[i];
    cout << endl;
    return 0;
}

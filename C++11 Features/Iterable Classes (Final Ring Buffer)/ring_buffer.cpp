#include "ring.h"

int main() {


    ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    // textring.add("five");
    // textring.add("six");
    // textring.add("seven");

    for (int i=0; i<textring.size(); i++) {
        cout << textring.get(i) << " " << flush;
    }

    cout << endl;

    // C++ 98 style
    for (ring<string>::iterator it=textring.begin(); 
        it!=textring.end(); it++) {
        cout << *it << " " << flush;
        // cout << endl << endl;
    }

    cout << endl;

    // C++ 11 style
    for (string text: textring) {
        cout << text << " " << flush;
    }

    cout << endl;

    return 0;
}

#include "ring.h"

int main() {

    ring<string> textring_init (3, {"A", "B", "C", "D"});
    for (auto &s: textring_init) {
        cout << s << " " << flush;
    }
    cout << endl << endl;

    ring<string> textring_init2 {"A", "B", "C", "D"};
    textring_init2.add("E");
    for (auto &s: textring_init2) {
        cout << s << " " << flush;
    }
    cout << endl << endl;

    ring<string> textring(4);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");
    textring.add("six");
    textring.add("seven");

    cout << "Using index based access: ";
    for (int i=0; i<textring.size(); i++) {
        cout << textring.get(i) << " " << flush;
    }

    cout << endl << endl;

    // C++ 98 style
    cout << "Using C++98 style iterator: ";
    for (ring<string>::iterator it=textring.begin(); 
        it!=textring.end(); it++) {
        cout << *it << " " << flush;
        // cout << endl << endl;
    }

    cout << endl << endl;

    // C++ 11 style
    cout << "Using C++11 style iterator: ";
    for (string &text: textring) {
        cout << text << " " << flush;
    }

    cout << endl;

    return 0;
}

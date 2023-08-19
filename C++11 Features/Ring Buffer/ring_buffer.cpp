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

    return 0;
}

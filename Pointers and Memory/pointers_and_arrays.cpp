#include <iostream>
using namespace std;

int main() {
    string texts[] = {"one", "two", "three", "four"};

    string *pTexts = texts;
    // same as: string *pTexts = &texts[0];
    for (int i=0; i<sizeof(texts)/sizeof(string); i++) {
        cout << pTexts[i] << " " << flush;
        // same as: cout << texts[i] << " " << flush;
    }
    cout << endl;

    for (int i=0; i<sizeof(texts)/sizeof(string); i++, pTexts++) {
        cout << *pTexts << " " << flush;
    }
    cout << endl;

    string *pElements = &texts[0];
    string *pEnd = &texts[3];
    for (; pElements<=pEnd; pElements++) {
        cout << *pElements << " " << flush;
    }
    cout << endl;

    return 0;
}


    // cout << sizeof(string[0]) << endl; // puzzling
